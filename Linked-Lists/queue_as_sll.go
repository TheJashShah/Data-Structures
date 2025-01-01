package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type node struct {
	data int
	next *node
}

func Input(prompt string) int {

	reader := bufio.NewReader(os.Stdin)

	fmt.Print(prompt)
	i, _ := reader.ReadString('\n')

	input := strings.TrimSpace(i)

	num, err := strconv.Atoi(input)

	if err != nil {
		return -1
	}

	return num
}

func CreateNode(data int) *node {

	return &node{
		data: data,
		next: nil,
	}
}

func EnQueue(data int, head *node) *node {

	if head.data == -1 {
		head.data = data
	} else {

		temp := head
		new := CreateNode(data)

		for temp.next != nil {
			temp = temp.next
		}

		temp.next = new
	}

	return head
}

func DeQueue(head *node) *node {

	if head.data == -1 {
		fmt.Println("Queue is Empty.")
	} else if head.next == nil {

		fmt.Printf("Data Dequeued is: %v \n", head.data)
		head.data = -1

	} else {

		temp := head
		head = head.next
		fmt.Printf("Data Dequeued is: %v \n", temp.data)
	}

	return head
}

func Display(head *node) {

	if head.data == -1 {
		fmt.Println("Queue is Empty.")
		return
	}

	temp := head

	for temp != nil {
		fmt.Printf("%v ", temp.data)
		temp = temp.next
	}
}

func main() {

	head := &node{
		data: -1,
		next: nil,
	}

	for {
		fmt.Println()
		fmt.Println("1. Enqueue an element.")
		fmt.Println("2. Dequeue an element.")
		fmt.Println("3. Display Queue.")
		fmt.Println("4. Exit.")
		fmt.Println()

		choice := Input("Enter Your Choice: \n")

		switch choice {

		case -1:

			fmt.Println("Enter an integer.")

		case 1:

			data := Input("Enter your data: ")

			if data == -1 {
				fmt.Println("Enter an integer.")
				break
			}

			head = EnQueue(data, head)

		case 2:

			head = DeQueue(head)

		case 3:

			Display(head)

		case 4:

			fmt.Println("Exiting..")
			return

		default:
			fmt.Println("Enter an integer between 1 and 4.")
		}
	}

}
