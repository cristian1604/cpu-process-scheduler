# Multiple strategies CPU process scheduler simulator
## with Gantt table and basic metrics

Perform a quick analisys as execution order, average service time, waiting time, and service time for several process using multiple scheduling strategies.

## Download and run!

You can [download the last release binary files (Windows and GNU/Linux) here!](https://github.com/cristian1604/cpu-process-scheduler/releases/tag/1.0)

The last release is `1.0`. On next, I will upload it on english.

## Avaiable strategies

The avaiable modes on this program are classified by preemptive and non preemptive strategies:
### Preemptive strategies
 * **`Round Robin`** (with customizable quantum)
 * **`SRTF`** (Shortest Remaining Time First)
 * **`Priority Preemptive`** (At lower value, has higher priority)

### Non preemptive strategies
 * **`FCFS`** (First Come First Served, based on FIFO)
 * **`SJF`** (Shortest Job First)
 * **`Priority non preemptive`** (At lower value, has higher priority)


## Snapshots

### Main window
![Main](https://raw.githubusercontent.com/cristian1604/cpu-process-scheduler/master/snapshots/main.png)


### Round Robin scheduling
![Round Robin Example](https://raw.githubusercontent.com/cristian1604/cpu-process-scheduler/master/snapshots/rr.png)

## About
Written by Cristian Bottazzi.

*This project was created as Operating Systems final project assignment. Computer Engineering at Facultad de Ingeniería y Ciencias Hídricas.*

The GUI was developed using wxWidgets.

Notes about efficency: This project was developed with few optimizations on iterative methods. The source code must be optimized for production purposes, but I've decided leave *as is* for clarity on the study of these algorithms on academic envirorments.
