package main

import (
	"fmt"
	"time"
	"math/rand"
	"sync"
	"runtime"
	"strconv"
	"strings"
)


func main() {
	rand.Seed(int64(time.Now().Nanosecond()))
	var wg sync.WaitGroup
	
	size := 3
	mat1 := [3][3]int{ { 4, 3, 1 }, { 3, 7, 2 }, { 4, 9, 1 } }
	mat2 := [3][3]int{ { 4, 10, 9 }, { 7, 10, 2 }, { 6, 4, 7 } }
	result := [3][3]int{}

	// size := 100
	// mat1 := [100][100]int{}
	// mat2 := [100][100]int{}
	// result := [100][100]int{}
	
	// for i:= 0; i < size; i++ {
	// 	for j:= 0; j < size; j++ {
	// 		mat1[i][j] = rand.Intn(1000) 
	// 		mat2[i][j] = rand.Intn(1000) 
	// 		}
	// }
	



	//var ch = make(chan int, 50)
	
	startTime := time.Now()
	for i:=0 ; i < size ; i++{
		wg.Add(1)
		
		go func(){
			defer wg.Done()
			fmt.Println(i, goid())
			sumMeUp(size, mat1, mat2, result, wg)
		}()
		
	}
	
	wg.Wait()

	t := time.Now()
	runTime := t.Sub(startTime)
	fmt.Println()
	fmt.Println(runTime)
	
	
}

func sumMeUp(size int, mat1 [3][3]int, mat2 [3][3]int, result [3][3]int, wg sync.WaitGroup ) {
	sum := 0
	for row := 0 ; row < size;  row++ {
			for col := 0 ; col < size ; col++ {
				for k := 0 ; k < size ; k++ {
					sum = sum + mat1[row][k] * mat2[k][col]
				}
			result[row][col] = sum
			sum = 0
			}
	}


	for i := 0; i < size; i++ {
		for j := 0; j < size ; j++ {
			fmt.Print(result[i][j])
			fmt.Print("\t")
		}
	 		fmt.Println()
	}
	
}


func goid() int {
	var buf [64]byte
	n := runtime.Stack(buf[:], false)
	idField := strings.Fields(strings.TrimPrefix(string(buf[:n]), "goroutine "))[0]
	id, err := strconv.Atoi(idField)
	if err != nil {
		panic(fmt.Sprintf("cannot get goroutine id: %v", err))
	}
	return id
}
