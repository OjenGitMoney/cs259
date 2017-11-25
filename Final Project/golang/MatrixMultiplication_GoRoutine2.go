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

	// size := 3
	// mat1 := [3][3]int{ { 4, 3, 1 }, { 3, 7, 2 }, { 4, 9, 1 } }
	// mat2 := [3][3]int{ { 4, 10, 9 }, { 7, 10, 2 }, { 6, 4, 7 } }
	// result := [3][3]int{}

	size := 400
	mat1 := [400][400]int{}
	mat2 := [400][400]int{}
	result := [400][400]int{}
	
	for i:= 0; i < size; i++ {
		for j:= 0; j < size; j++ {
			mat1[i][j] = rand.Intn(1000) 
			mat2[i][j] = rand.Intn(1000) 
			}
	}
	



	//var ch = make(chan int, 50)
	
	startTime := time.Now()
		
				//fmt.Println(i, goid())
						wg.Add(1)
						go func(){
							
							defer wg.Done()
							for row := 0 ; row < size;  row++ {
								for col := 0 ; col < size ; col++ {
								
								
								sumMeUp(row, col, size, mat1, mat2, result)
						
								}
							}
						}()
				

	wg.Wait()

	

	t := time.Now()
	runTime := t.Sub(startTime)
	fmt.Println()
	fmt.Println(runTime)
	
	
}

func sumMeUp(row int, col int, size int, mat1 [400][400]int, mat2 [400][400]int, result [400][400]int) {
	var mutex = &sync.Mutex{}
	sum := 0
	
	for k := 0 ; k < size ; k++ {
		sum = sum + mat1[row][k] * mat2[k][col]
	}

	mutex.Lock()
	result[row][col] = sum
	mutex.Unlock()


	// fmt.Println()
	// for i := 0; i < size; i++ {
	// 	for j := 0; j < size ; j++ {
	// 		fmt.Print(result[i][j])
	// 		fmt.Print("\t")
	// 	}
	//  		fmt.Println()
	// 	}	
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
