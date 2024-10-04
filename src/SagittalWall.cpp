#include "SagittalWall.h"

SagittalWall::SagittalWall(mc_rbdyn::RobotModulePtr rm, double dt, const mc_rtc::Configuration & config)
: mc_control::fsm::Controller(rm, dt, config)
{

  mc_rtc::log::success("SagittalWall init done ");
}

bool SagittalWall::run()
{
  return mc_control::fsm::Controller::run();
}

void SagittalWall::reset(const mc_control::ControllerResetData & reset_data)
{
  mc_control::fsm::Controller::reset(reset_data);
}


