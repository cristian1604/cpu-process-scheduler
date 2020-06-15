# Multiple strategies CPU process scheduler simulator
## with Gantt table and basic metrics

Perform a quick analisys as execution order, average service time, waiting time, and service time for several process using multiple scheduling strategies.

The GUI was developed using wxWidgets.

## Avaiable modes

The modes avaiables on this program are preemptive and non preemptive:
### Preemptive strategies
 * **`Round Robin`** (with customizable quantum)
 * **`SRTF`** (Shortest Remaining Time First)

### Non preemptive strategies
 * **`FCFS`** (First Come First Served, based on FIFO)
 * **`SJF`** (Shortest Job First)


## Snapshots

### Main window
![Main](https://raw.githubusercontent.com/cristian1604/cpu-process-scheduler/master/snapshots/main.png)


### Round Robin scheduling
![Round Robin Example](https://raw.githubusercontent.com/cristian1604/cpu-process-scheduler/master/snapshots/rr.png)

## About
Written by Cristian Bottazzi.

*This project was created as final project of Sistemas Operativos (operating systems) assignment, Computer Engineering at Facultad de Ingeniería y Ciencias Hídricas.*