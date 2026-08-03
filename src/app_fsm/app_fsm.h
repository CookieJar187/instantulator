#pragma once

enum class AppState {
    Main,
    Settings,
    Help,
    Quit
};

class AppFsm {
public:
    AppFsm();

    AppState getState() const;
    bool isState(const AppState& newState) const;
    void setState(const AppState& newState);

private:
    AppState currState;

};