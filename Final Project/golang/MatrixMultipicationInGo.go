package main

import (
	"fmt"
	"time"
	"math/rand"
)

func main() {
	size := 3
	//mat1 := [3][3]int{}
	mat1 := [3][3]int{ { 4, 3, 1 }, { 3, 7, 2 }, { 4, 9, 1 } }
	//mat2 := [3][3]int{}
	mat2 := [3][3]int{ { 4, 10, 9 }, { 7, 10, 2 }, { 6, 4, 7 } }
	result := [3][3]int{}

	rand.Seed(int64(time.Now().Nanosecond()))
	
	// for i:= 0; i < size; i++ {
	// 	for j:= 0; j < size; j++ {
	// 		mat1[i][j] = rand.Intn(10) 
	// 		mat2[i][j] = rand.Intn(10) 
	// 		}
	// }
	
	 for i := 0; i < size; i++ {
		for j := 0; j < size ; j++ {
			fmt.Print(mat1[i][j])
			fmt.Print("\t")
		}
	 		fmt.Println()
		}
		fmt.Println()
		fmt.Println()
	for i := 0; i < size; i++ {
		for j := 0; j < size ; j++ {
			fmt.Print(mat2[i][j])
			fmt.Print("\t")
		}
	 		fmt.Println()
		}	
	
	
	sum := 0
	startTime := time.Now()

	for row := 0 ; row < size;  row++ {
		for col := 0 ; col < size ; col++ {
			
			for k := 0 ; k < size ; k++ {

                sum = sum + mat1[row][k] * mat2[k][col];
			}
			result[row][col] = sum;
			sum = 0;
		}
			
	}

	fmt.Println()
	fmt.Println()
	for i := 0; i < size; i++ {
		for j := 0; j < size ; j++ {
			fmt.Print(result[i][j])
			fmt.Print("\t")
		}
	 		fmt.Println()
		}



	//time.Sleep(time.Second * 3)

	t := time.Now()
	runTime := t.Sub(startTime)
	fmt.Println(runTime)
}
