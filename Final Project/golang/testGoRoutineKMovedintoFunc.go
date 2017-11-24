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

	// size := 3
	// mat1 := [3][3]int{ { 4, 3, 1 }, { 3, 7, 2 }, { 4, 9, 1 } }
	// mat2 := [3][3]int{ { 4, 10, 9 }, { 7, 10, 2 }, { 6, 4, 7 } }
	// result := [3][3]int{}

	rand.Seed(int64(time.Now().Nanosecond()))
	for i:= 0; i < size; i++ {
		for j:= 0; j < size; j++ {
			mat1[i][j] = rand.Intn(1000) 
			mat2[i][j] = rand.Intn(1000) 
			}
	}
	
	//sum := 0
	startTime := time.Now()

	for row := 0 ; row < size;  row++ {
		for col := 0 ; col < size ; col++ {
			
			result[row][col] = sumMeUp(row, col, size, mat1, mat2)
			//sum = 0;
		}
			
	}
	fmt.Println()
	for i := 0; i < size; i++ {
		for j := 0; j < size ; j++ {
			fmt.Print(result[i][j])
			fmt.Print("\t")
		}
	 		fmt.Println()
		}

	fmt.Println()
	t := time.Now()
	runTime := t.Sub(startTime)
	fmt.Println(runTime)
}

func sumMeUp(row int, col int, size int, mat1 [100][100]int, mat2 [100][100]int) int {
	sum := 0
	for k := 0 ; k < size ; k++ {
		sum = sum + mat1[row][k] * mat2[k][col]
	}
	return sum
}
