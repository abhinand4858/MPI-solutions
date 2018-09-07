# MPI-solutions
MPI assignment solutions

## Questions
 - Write a program that uses MPI and has each process print the message "This is from process i of n", where i is the rank of process in
MPI_COMM_WORLD and n is the number of process.
 - Write a MPI program with two processes: a master and a slave process. Master process with rank 0 reads a integer input from the terminal and send to the slave
process. The slave process with rank 1 print out value it received.
 - Modify above program with n slaves. Each slave process print out value it
received.(Hint: Use MPI_BCast procedure)
- mpute standard deviation of n numbers using n process
  - Generate a random number Xi at each process i
  - Gather all numbers to the root process. The root process then computes the average x̅ of these numbers
  - Broadcast the value of x̅ to all processes and compute (Xi - x̅) 2 in each process
  - Gather the value of (Xi - x̅) 2 from the each process to the root process and calculate the standard deviation
