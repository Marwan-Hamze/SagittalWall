#include "SagittalWall_Initial.h"

#include "../SagittalWall.h"

void SagittalWall_Initial::configure(const mc_rtc::Configuration & config)
{
}

void SagittalWall_Initial::start(mc_control::fsm::Controller & ctl_)
{
  auto & ctl = static_cast<SagittalWall &>(ctl_);
}

bool SagittalWall_Initial::run(mc_control::fsm::Controller & ctl_)
{
  auto & ctl = static_cast<SagittalWall &>(ctl_);
  output("OK");
  return true;
}

void SagittalWall_Initial::teardown(mc_control::fsm::Controller & ctl_)
{
  auto & ctl = static_cast<SagittalWall &>(ctl_);
}

EXPORT_SINGLE_STATE("SagittalWall_Initial", SagittalWall_Initial)
