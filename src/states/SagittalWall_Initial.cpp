#include "SagittalWall_Initial.h"

#include "../SagittalWall.h"

void SagittalWall_Initial::configure(const mc_rtc::Configuration & config)
{
}

void SagittalWall_Initial::start(mc_control::fsm::Controller & ctl_)
{

  ctl_.gui()->addElement({"Controller"}, mc_rtc::gui::Button("Move Right Hand", [this]() { start_ = true; }));
  auto & ctl = static_cast<SagittalWall &>(ctl_);
}

bool SagittalWall_Initial::run(mc_control::fsm::Controller & ctl_)
{
 if(start_)
  {
    output("OK");
    return true;
  }
  return false;
}

void SagittalWall_Initial::teardown(mc_control::fsm::Controller & ctl_)
{
  auto & ctl = static_cast<SagittalWall &>(ctl_);
  ctl_.gui()->removeElement({"Controller"},"Move Right Hand");

}

EXPORT_SINGLE_STATE("SagittalWall_Initial", SagittalWall_Initial)
