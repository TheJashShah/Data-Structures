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

func getLength(head *node) int {

	len := 1

	if head.data == -1 {
		len = 0

	} else if head.next == nil {
		len = 1

	} else {

		temp := head

		for temp.next != nil {
			len++
			temp = temp.next
		}
	}

	return len
}

func AddAtEnd(data int, head *node) *node {

	if head.data == -1 {
		head.data = data

	} else {

		new := CreateNode(data)

		temp := head

		for temp.next != nil {
			temp = temp.next
		}

		temp.next = new
	}

	return head

}

func AddAtStart(data int, head *node) *node {

	if head.data == -1 {
		head.data = data

	} else {

		new := CreateNode(data)

		new.next = head
		head = new
	}

	return head
}

func AddAtIndex(data int, index int, head *node) *node {

	if head.data == -1 {
		head.data = data

	} else {

		len := getLength(head)

		if len <= index {
			fmt.Println("Index is not Present in the List.")
		} else {

			i := 1
			temp := head

			for i != (index - 1) {
				temp = temp.next
				i++
			}

			new := CreateNode(data)

			new.next = temp.next
			temp.next = new
		}

	}

	return head
}

func RemoveAtEnd(head *node) *node {

	if head.data == -1 {
		fmt.Println("No Node in the List.")

	} else if head.next == nil {
		head.data = -1

	} else {

		temp := head

		for temp.next.next != nil {
			temp = temp.next
		}

		fmt.Printf("Data Removed is: %v \n", temp.next.data)
		temp.next = nil
	}

	return head
}

func RemoveAtStart(head *node) *node {

	if head.data == -1 {
		fmt.Println("No Node in the List.")

	} else if head.next == nil {
		head.data = -1

	} else {

		temp := head
		head = head.next
		fmt.Printf("Data Removed is %v \n", temp.data)

	}

	return head

}

func DisplayList(head *node) {

	if head.data == -1 {
		fmt.Println("No Node in the List.")
		return
	}

	temp := head

	for temp != nil {
		fmt.Printf("%v  ", temp.data)
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
		fmt.Println("1. Add a New Node at the End.")
		fmt.Println("2. Add a New Node at the Start.")
		fmt.Println("3. Remove a Node from the End.")
		fmt.Println("4. Remove a Node from the Start.")
		fmt.Println("5. Add a New Node at a particular Index.")
		fmt.Println("6. Display the List.")
		fmt.Println("7. Exit.")
		fmt.Println()

		choice := Input("\nEnter your Choice: \n")

		switch choice {

		case -1:

			fmt.Println("Enter an integer.")

		case 1:

			data := Input("Enter your data: ")

			if data == -1 {
				fmt.Println("Enter an integer.")
				break
			}

			head = AddAtEnd(data, head)

		case 2:

			data := Input("Enter your data: ")

			if data == -1 {
				fmt.Println("Enter an integer.")
				break
			}

			head = AddAtStart(data, head)

		case 3:

			head = RemoveAtEnd(head)

		case 4:

			head = RemoveAtStart(head)

		case 5:

			index := Input("Enter your Index: ")

			if index == -1 {
				fmt.Println("Enter an integer.")
				break
			}

			data := Input("Enter your data: ")

			if data == -1 {
				fmt.Println("Enter an integer.")
				break
			}

			head = AddAtIndex(data, index, head)

		case 6:

			fmt.Println("The List is: ")
			DisplayList(head)
			fmt.Println()

		case 7:

			fmt.Println("Exiting...")
			return

		default:

			fmt.Println("Enter an integer between 1 and 7.")

		}
	}

}
