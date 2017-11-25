package main

import (
	"fmt"
	"time"
	"math/rand"
	"sync"
)

func main() {
	size := 10
	mat1 := [10][10]int{}
	mat2 := [10][10]int{}
	result := [10][10]int{}
	var wg = sync.WaitGroup{}

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

	startTime := time.Now()
	
	go func(size int, mat1 [10][10]int, mat2 [10][10]int, result [10][10]int){
	wg.Add(1)	
	sumL := 0	
	
	for row := 0 ; row < size;  row++ {
		for col := 0 ; col < size ; col++ {
		
				for k := 0 ; k < size ; k++ {
						
						sumL= sumL + mat1[row][k] * mat2[k][col]
					
					}
					result[row][col] = sumL
					wg.Done()
				}
		}
			
	}(size, mat1, mat2, result)
	wg.Wait()

	// fmt.Println()
	// for i := 0; i < size; i++ {
	// 	for j := 0; j < size ; j++ {
	// 		fmt.Print(result[i][j])
	// 		fmt.Print("\t")
	// 	}
	//  		fmt.Println()
	// 	}

	fmt.Println()
	t := time.Now()
	runTime := t.Sub(startTime)
	fmt.Println(runTime)
}

