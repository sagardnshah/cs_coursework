//SAGAR SHAH
#include "stdio.h"

int main(void) {

  /*
    Unless otherwise indicated, all statments in the code REQUIRE
    incrementation of the opTime variable.

    The amount of time that an internal unit uses during operation is given in the pdf.

    There are five internal units, and different instructions require particular units to operate.
    opTime += 0;  // IF (Instruction Fetch) unit
    opTime += 0;  // ID (Instruction Decode) unit
    opTime += 0;  // OF (Operand Fetch) unit
    opTime += 0;  // OE (Operation Execution) unit
    opTime += 0;  // OS (Operant Store) unit
  */

  // To keep track of runtime
  // DO NOT include in opTime calculation!
  float opTime = 0.0;

  //An arbitrary number for use as a condition in second 'for' loop
  int n = 1000;
            opTime += 800;  // IF (Instruction Fetch) unit
            opTime += 100;  // ID (Instruction Decode) unit
            opTime += 0;  // OF (Operand Fetch) unit
            opTime += 200;  // OE (Operation Execution) unit
            opTime += 800;  // OS (Operant Store) unit

  //some float variables that represent registers and memory locations
  float x = 1;
            opTime += 800;  // IF (Instruction Fetch) unit
            opTime += 100;  // ID (Instruction Decode) unit
            opTime += 0;  // OF (Operand Fetch) unit
            opTime += 200;  // OE (Operation Execution) unit
            opTime += 800;  // OS (Operant Store) unit
  float y = 1;
            opTime += 800;  // IF (Instruction Fetch) unit
            opTime += 100;  // ID (Instruction Decode) unit
            opTime += 0;  // OF (Operand Fetch) unit
            opTime += 200;  // OE (Operation Execution) unit
            opTime += 800;  // OS (Operant Store) unit
  float z = 1;
            opTime += 800;  // IF (Instruction Fetch) unit
            opTime += 100;  // ID (Instruction Decode) unit
            opTime += 0;  // OF (Operand Fetch) unit
            opTime += 200;  // OE (Operation Execution) unit
            opTime += 800;  // OS (Operant Store) unit
  float t = 0;
            opTime += 800;  // IF (Instruction Fetch) unit
            opTime += 100;  // ID (Instruction Decode) unit
            opTime += 0;  // OF (Operand Fetch) unit
            opTime += 200;  // OE (Operation Execution) unit
            opTime += 800;  // OS (Operant Store) unit
  float k = 1;
            opTime += 800;  // IF (Instruction Fetch) unit
            opTime += 100;  // ID (Instruction Decode) unit
            opTime += 0;  // OF (Operand Fetch) unit
            opTime += 200;  // OE (Operation Execution) unit
            opTime += 800;  // OS (Operant Store) unit



  // Iterator declaration; In C, declaring 'i' must be done before initializing a 'for' loop
  // DO NOT include in opTime calculation!
  int i;

  // Assume 'for' loop instruction is read only one time, but it checks and incremants i 100 times!
  // Each command requires incrementing opTime variable relative to what it does.
    
    //for command
    opTime += 800;  // IF (Instruction Fetch) unit
    opTime += 100;  // ID (Instruction Decode) unit
    opTime += 0;  // OF (Operand Fetch) unit
    opTime += 0;  // OE (Operation Execution) unit
    opTime += 0;  // OS (Operant Store) unit
    
    //i=0
    opTime += 800;  // IF (Instruction Fetch) unit
    opTime += 100;  // ID (Instruction Decode) unit
    opTime += 0;  // OF (Operand Fetch) unit
    opTime += 200;  // OE (Operation Execution) unit
    opTime += 800;  // OS (Operant Store) unit
    
  for( i = 0 ; i<100; i++)
  {
    //check i<100
    opTime += 0;  // IF (Instruction Fetch) unit
    opTime += 0;  // ID (Instruction Decode) unit
    opTime += 0;  // OF (Operand Fetch) unit
    opTime += 200;  // OE (Operation Execution) unit
    opTime += 0;  // OS (Operant Store) unit
    
    x = y + z;
          opTime += 800;  // IF (Instruction Fetch) unit
          opTime += 100;  // ID (Instruction Decode) unit
          opTime += 1600;  // OF (Operand Fetch) unit
          opTime += 200;  // OE (Operation Execution) unit
          opTime += 800;  // OS (Operant Store) unit
    
    y = x;
          opTime += 800;  // IF (Instruction Fetch) unit
          opTime += 100;  // ID (Instruction Decode) unit
          opTime += 800;  // OF (Operand Fetch) unit
          opTime += 200;  // OE (Operation Execution) unit
          opTime += 800;  // OS (Operant Store) unit
    
    z = y + i;
          opTime += 800;  // IF (Instruction Fetch) unit
          opTime += 100;  // ID (Instruction Decode) unit
          opTime += 1600;  // OF (Operand Fetch) unit
          opTime += 200;  // OE (Operation Execution) unit
          opTime += 800;  // OS (Operant Store) unit
          
    //i++
    opTime += 800;  // IF (Instruction Fetch) unit
    opTime += 100;  // ID (Instruction Decode) unit
    opTime += 800;  // OF (Operand Fetch) unit
    opTime += 200;  // OE (Operation Execution) unit
    opTime += 800;  // OS (Operant Store) unit
  }
  printf("\n x = %f\n y = %f\n z = %f\n t = %f\n k = %f\n Operating time 01 = %f ns \n\n\n", x,y,z,t,k, opTime);
          opTime += 800;  // IF (Instruction Fetch) unit
          opTime += 100;  // ID (Instruction Decode) unit
          opTime += 4800;  // OF (Operand Fetch) unit
          opTime += 200;  // OE (Operation Execution) unit
          opTime += 0;  // OS (Operant Store) unit


  //re-initializing registers and memory locations
  x = 1;
          opTime += 800;  // IF (Instruction Fetch) unit
          opTime += 100;  // ID (Instruction Decode) unit
          opTime += 0;  // OF (Operand Fetch) unit
          opTime += 200;  // OE (Operation Execution) unit
          opTime += 800;  // OS (Operant Store) unit
  y = 0;
          opTime += 800;  // IF (Instruction Fetch) unit
          opTime += 100;  // ID (Instruction Decode) unit
          opTime += 0;  // OF (Operand Fetch) unit
          opTime += 200;  // OE (Operation Execution) unit
          opTime += 800;  // OS (Operant Store) unit
  z = 0;
          opTime += 800;  // IF (Instruction Fetch) unit
          opTime += 100;  // ID (Instruction Decode) unit
          opTime += 0;  // OF (Operand Fetch) unit
          opTime += 200;  // OE (Operation Execution) unit
          opTime += 800;  // OS (Operant Store) unit
  t = 0;
          opTime += 800;  // IF (Instruction Fetch) unit
          opTime += 100;  // ID (Instruction Decode) unit
          opTime += 0;  // OF (Operand Fetch) unit
          opTime += 200;  // OE (Operation Execution) unit
          opTime += 800;  // OS (Operant Store) unit
  k = 0;
          opTime += 800;  // IF (Instruction Fetch) unit
          opTime += 100;  // ID (Instruction Decode) unit
          opTime += 0;  // OF (Operand Fetch) unit
          opTime += 200;  // OE (Operation Execution) unit
          opTime += 800;  // OS (Operant Store) unit

  // Assume for instruction is read only onetime, but it checks and incremants i for 1000 times! n is initialized before.
  
    //for command
    opTime += 800;  // IF (Instruction Fetch) unit
    opTime += 100;  // ID (Instruction Decode) unit
    opTime += 0;  // OF (Operand Fetch) unit
    opTime += 0;  // OE (Operation Execution) unit
    opTime += 0;  // OS (Operant Store) unit
    
    //i=0
    opTime += 800;  // IF (Instruction Fetch) unit
    opTime += 100;  // ID (Instruction Decode) unit
    opTime += 0;  // OF (Operand Fetch) unit
    opTime += 200;  // OE (Operation Execution) unit
    opTime += 800;  // OS (Operant Store) unit
  for( i = 0; i < n ; i++)
  {
    //i<n
    opTime += 0;  // IF (Instruction Fetch) unit
    opTime += 0;  // ID (Instruction Decode) unit
    opTime += 800;  // OF (Operand Fetch) unit
    opTime += 200;  // OE (Operation Execution) unit
    opTime += 0;  // OS (Operant Store) unit
    
    y = t + 1;
    opTime += 800;  // IF (Instruction Fetch) unit
    opTime += 100;  // ID (Instruction Decode) unit
    opTime += 800;  // OF (Operand Fetch) unit
    opTime += 200;  // OE (Operation Execution) unit
    opTime += 800;  // OS (Operant Store) unit
    k = k + 5;
    opTime += 800;  // IF (Instruction Fetch) unit
    opTime += 100;  // ID (Instruction Decode) unit
    opTime += 800;  // OF (Operand Fetch) unit
    opTime += 200;  // OE (Operation Execution) unit
    opTime += 800;  // OS (Operant Store) unit
    z++;
    opTime += 800;  // IF (Instruction Fetch) unit
    opTime += 100;  // ID (Instruction Decode) unit
    opTime += 800;  // OF (Operand Fetch) unit
    opTime += 200;  // OE (Operation Execution) unit
    opTime += 800;  // OS (Operant Store) unit
    t = t + i;
    opTime += 800;  // IF (Instruction Fetch) unit
    opTime += 100;  // ID (Instruction Decode) unit
    opTime += 1600;  // OF (Operand Fetch) unit
    opTime += 200;  // OE (Operation Execution) unit
    opTime += 800;  // OS (Operant Store) unit
    
    //i++
    opTime += 800;  // IF (Instruction Fetch) unit
    opTime += 100;  // ID (Instruction Decode) unit
    opTime += 800;  // OF (Operand Fetch) unit
    opTime += 200;  // OE (Operation Execution) unit
    opTime += 800;  // OS (Operant Store) unit

  }

  printf("\n x = %f\n y = %f\n z = %f\n t = %f\n k = %f\n Total operating time = %f ns\n\n\n", x,y,z,t,k, opTime);
          opTime += 800;  // IF (Instruction Fetch) unit
          opTime += 100;  // ID (Instruction Decode) unit
          opTime += 4800;  // OF (Operand Fetch) unit
          opTime += 200;  // OE (Operation Execution) unit
          opTime += 0;  // OS (Operant Store) unit


  // Do not include in opTime calculation!
  return 0;
}
