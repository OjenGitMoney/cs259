package main

import (
	"fmt"
	"time"
	"math/rand"
)

func main() {
	size := 3
	mat1 := [1000][1000]int{}
	mat2 := [1000][1000]int{}
	result := [1000][1000]int{}

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

             sum = sumMeUp(row, col, k, mat1, mat2, sum) 
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

func sumMeUp(row int, col int, k int, mat1 [1000][1000]int, mat2 [1000][1000]int, sum int) int {
	sum = sum + mat1[row][k] * mat2[k][col]
	return sum
}
