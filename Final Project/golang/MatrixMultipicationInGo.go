package main

import (
	"fmt"
	"time"
	"math/rand"
)

func main() {
	size := 3
	mat1 := [3][3]int{}
	mat2 := [3][3]int{}

	rand.Seed(int64(time.Now().Nanosecond()))
	
	for i:= 0; i < size; i++ {
		for j:= 0; j < size; j++ {
			mat1[i][j] = rand.Intn(1000) 
			mat2[i][j] = rand.Intn(1000) 

			}
	}
	
	
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
	
	
}
