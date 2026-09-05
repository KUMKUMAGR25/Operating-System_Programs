# C++ Programs
## OS Practicals
<br>
# 1.FCFS CPU Scheduling
<br>
FCFS is a CPU scheduling algorithm in which the process that arrives first in the ready queue gets executed first.
<br>
● It follows the FIFO (First In, First Out) principle.
<br>
● It is a non-preemptive scheduling algorithm.
<br>
● Once a process gets the CPU, it runs until it finishes.
<br>
<br>
# 2. Priority CPU Scheduling 
<br>
Priority Scheduling is a CPU scheduling algorithm in which the CPU is assigned to the process having the highest priority.
<br>
● Each process is given a priority value.
The process with the highest priority is executed first.
<br>
● It can be preemptive or non-preemptive.
In many systems, a smaller priority number means higher priority.
<br>
<br>
# 3. Round Robin CPU Scheduling
<br>
Round Robin is a preemptive CPU scheduling algorithm in which each process gets a fixed amount of CPU time called a Time Quantum (Time Slice).
<br>
● Processes are executed in circular/FIFO order.
<br>
● Each process gets the CPU for one time quantum.
<br>
● If a process is not completed within the quantum, it is preempted and moved to the end of the ready queue.
<br>
● It is commonly used in time-sharing systems.
<br>
<br>
# 4.SJF CPU Scheduling
<br>
SJF is a CPU scheduling algorithm in which the process having the shortest CPU burst time is executed first.
<br>
● It can be preemptive or non-preemptive.
<br>
● In non-preemptive SJF, once a process starts, it runs until completion.
<br>
● In preemptive SJF, also called Shortest Remaining Time First (SRTF), a newly arrived shorter process can interrupt the current process.
<br>
<br>
5. Compare various CPU Scheduling.
<br>
● FCFS: Simple and fair by arrival order, but may have high waiting time.
<br>
● SJF: Gives minimum average waiting time, but may cause starvation.
<br>
● Priority: Executes high-priority processes first, but low-priority processes may starve.
<br>
● Round Robin: Gives each process equal CPU time and good response, but causes more context switching.
<br>

