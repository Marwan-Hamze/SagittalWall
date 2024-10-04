#include "SagittalWall.h"

SagittalWall::SagittalWall(mc_rbdyn::RobotModulePtr rm, double dt, const mc_rtc::Configuration & config)
: mc_control::fsm::Controller(rm, dt, config)
{

  config_.load(config);

  datastore().make_call("KinematicAnchorFrame::" + robot().name(),
                          [this](const mc_rbdyn::Robot & robot)
                          {
                            return sva::interpolate(robot.surfacePose("LeftFoot"),
                                                    robot.surfacePose("RightFoot"),
                                                    leftFootRatio);
                          });

  logger().addLogEntry("Kaleido_CoM", [this]() { return realRobots().robot().com(); });
  logger().addLogEntry("RightHand_Force", [this]() {return realRobots().robot().forceSensor("RightHandForceSensor").wrenchWithoutGravity(realRobots().robot()).force();});
  logger().addLogEntry("RightHand_Velocity_Linear", [this]() { return realRobots().robot().bodyVelW("R_HAND_LINK").linear(); });

  mc_rtc::log::success("SagittalWall init done ");
}

bool SagittalWall::run()
{
  
  t_ += timeStep;

  return mc_control::fsm::Controller::run();
}

void SagittalWall::reset(const mc_control::ControllerResetData & reset_data)
{

  const auto & observerp = observerPipeline(observerPipelineName_);
  
  if(observerp.success())
  {
    mc_rtc::log::info("Pipeline \"{}\" for real robot observation loaded!", observerPipelineName_);
  }

  using Color = mc_rtc::gui::Color;

  gui()->addPlot(
    "Right Hand Force (t)", mc_rtc::gui::plot::X("t", [this]() { return t_; }),
    mc_rtc::gui::plot::Y(
        "f_RH(z)", [this]() { return realRobots().robot().forceSensor("RightHandForceSensor").wrenchWithoutGravity(realRobots().robot()).force().z(); }, Color::Red), 
    mc_rtc::gui::plot::Y(
        "f_RH(x)", [this]() { return realRobots().robot().forceSensor("RightHandForceSensor").wrenchWithoutGravity(realRobots().robot()).force().x(); }, Color::Green),
    mc_rtc::gui::plot::Y(
        "f_RH(y)", [this]() { return realRobots().robot().forceSensor("RightHandForceSensor").wrenchWithoutGravity(realRobots().robot()).force().y(); }, Color::Blue)
        ); 

  mc_control::fsm::Controller::reset(reset_data);
}


