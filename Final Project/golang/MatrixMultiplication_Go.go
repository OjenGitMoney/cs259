package main

import (
	"fmt"
	"time"
	"math/rand"
)

func main() {
	size := 100
	mat1 := [100][100]int{}
	mat2 := [100][100]int{}
	result := [100][100]int{}

	rand.Seed(int64(time.Now().Nanosecond()))
	
	for i:= 0; i < size; i++ {
		for j:= 0; j < size; j++ {
			mat1[i][j] = rand.Intn(1000) 
			mat2[i][j] = rand.Intn(1000) 
			}
	}
	
	sum := 0
	startTime := time.Now()

	for row := 0 ; row < size;  row++ {
		for col := 0 ; col < size ; col++ {
			
			for k := 0 ; k < size ; k++ {

                sum = sum + mat1[row][k] * mat2[k][col]

			}
			result[row][col] = sum;
			sum = 0;
		}
			
	}

	fmt.Println()
	t := time.Now()
	runTime := t.Sub(startTime)
	fmt.Println(runTime)
}
