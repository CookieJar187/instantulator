#include "app_fsm.h"

AppFsm::AppFsm()
{ currState = AppState::Main; }

AppState AppFsm::getState() const
{ return AppFsm::currState; }

bool AppFsm::isState(const AppState& newState) const
{ return AppFsm::currState == newState; }

void AppFsm::setState(const AppState& newState)
{ AppFsm::currState = newState; }