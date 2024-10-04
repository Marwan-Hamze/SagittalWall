#pragma once

#include <mc_control/mc_controller.h>
#include <mc_control/fsm/Controller.h>

#include "api.h"

struct SagittalWall_DLLAPI SagittalWall : public mc_control::fsm::Controller
{
  SagittalWall(mc_rbdyn::RobotModulePtr rm, double dt, const mc_rtc::Configuration & config);

  bool run() override;

  void reset(const mc_control::ControllerResetData & reset_data) override;

  protected:
  
  double t_ = 0; // Elapsed time since the controller started

  private:

    mc_rtc::Configuration config_;

    // GUI Related

    bool start = false;
    bool click = false;
    bool armPos = false;

    // Active Joints for the CoM and Base tasks

    std::vector<std::string> Activedof_;

  // Ratio for the kinematic inertial
    
  double leftFootRatio = 0.5;

  // Observer Pipeline
    
  std::string observerPipelineName_ = "KaleidoObserverPipeline";
};