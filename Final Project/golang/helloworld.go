package main

import "fmt"
import "time"

func main() {
    fmt.Printf("hello, world\n")
    fmt.Printf("%d" , time.Now().UTC().UnixNano())
    fmt.Printf("%d" , time.Now().UTC().UnixNano().(int))
	
	}