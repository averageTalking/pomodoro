# Pomodoro Terminal Tool in C

A simple command-line Pomodoro timer written in C for terminals:
- configurable session/pause durations
- real-time progress bar
- keyboard controls (Pause, Cancel, Restart)
- session history tracking
- and history management



## Installation

```bash
make         # Builds the application
make run     # Builds and runs the application
make clean   # Deletes the bin/ directory
```

## Features

>>> CONFIGURATION
Configuration of the duration for every session (optional)
```bash
pomodoro config <hh:mm:ss>
```

>>> SESSION with Configuration
```bash
pomodoro start
```

>>> SESSION without Configuration 
```bash
pomodoro start <hh:mm:ss>
```
```text
Working ...
<Prozentanzeige>% <Fortschrittsbalken>
```
Button "C" for Cancel current session after confirming that you really want to cancel
Button "R" for Restart current session after confirming that you really want to restart
Button "S" for Stop current session

>>> HISTORY
```bash
pomodoro history
```
```text
Here are your stats!
Session   Status     Time       Date
--------------------------------------------
1         FINISHED   00:25:00   2025-01-18
2         FAILED     10:30:00   2025-02-23
...       ...        ...        ...
n         n          n          n
```

>>> HISTORY MANAGEMENT
Delete the complete history of your sessions
```bash
pomodoro delete all
```
```text
Erfolgsnachricht
```

Delete a specific history of your sessions
```bash
pomodoro delete <session_number>
```
```text
Erfolgsnachricht
```
