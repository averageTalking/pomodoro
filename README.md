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

> CONFIGURATION
Configuration of the duration for every session (optional)
```bash
pomodoro config <hh:mm:ss>
```

> SESSION with Configuration
```bash
pomodoro start
```

> SESSION without Configuration 
```bash
pomodoro start <hh:mm:ss>
```
```text
Working ...
<Prozentanzeige>% <Fortschrittsbalken>
```
  
**Keyboard Controls:**

- **C** — Cancel current session (after confirmation)
- **R** — Restart current session (after confirmation)
- **S** — Stop current session


> HISTORY
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

> HISTORY MANAGEMENT - Delete the complete history of your sessions
```bash
pomodoro delete all
```
Wenn erfolgreich
```text
Successfully deleted. This is gone now!
```
Wenn fehlerhaft
```text
There has been an error!
```

> HISTORY MANAGEMENT - Delete a specific history of your sessions
```bash
pomodoro delete <session_number>
```
Wenn erfolgreich
```text
Successfully deleted. This is gone now!
```
Wenn fehlerhaft
```text
There has been an error!
```


## Project Structure
```
pomodoro/
├── bin/
├── src/
│   ├── main.c
│   └── main.h
├── .gitignore
├── Makefile
└── README.md/
```
