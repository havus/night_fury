// src: https://replit.com/@havus/binussmt2tp1#main.go

// You can edit this code!
// Click here and start typing.
package main

import (
  "bufio"
  "fmt"
  "os"
  "strings"
)

// Buatlah sebuah program database sederhana dengan menggunakan singly linked list!
// Program tersebut memiliki pilihan(menu) sebagai berikut:
// 1.	Push data karyawan. Ketika dijalankan, akan diminta input berupa Employee ID, Nama Lengkap, Tempat Lahir, Tanggal Lahir, dan Jabatan. Validasi Employee ID maksimal 5 angka, Nama Lengkap dan Tempat lahir maksimal 30 karakter, dan Jabatan maksimal 50 karakter. Validasi jumlah data yang dapat diinput adalah maksimal 5 data.
// 2.	Menampilkan semua daftar Karyawan di database terdiri dari Employee ID, Nama Lengkap, Tempat Tanggal Lahir, dan Jabatan. Data karyawan ditampilkan secara terurut (sort) berdasarkan Employee ID.
// 3.	Hapus data karyawan berdasarkan Employee ID
// 4.	Hapus semua data karyawan
// 5.	Keluar dari program.

type Employee struct {
  id         string
  fullName   string
  birthPlace string
  birthDay   string
  position   string
}

type Node struct {
	next  *Node
	value Employee
}
// type Node struct {
// 	next  *Node
// 	value string
// }

func main() {
	linkedListHead := Node{}
	// newNode := Node{value: "Hello"}
	// newNode2 := Node{value: "World"}

 //  insert(&linkedListHead, &newNode)
 //  insert(&linkedListHead, &newNode2)

	// last := findLastNodePtr(&linkedListHead)
 //  prev := findPreviousNode(&linkedListHead, last)
	// fmt.Println(prev.value, last.value, countLinkedList(&linkedListHead))

 //  removeNode(&linkedListHead, &newNode)
 //  last = findLastNodePtr(&linkedListHead)
 //  prev = findPreviousNode(&linkedListHead, last)
 //  fmt.Println(prev.value, last.value, countLinkedList(&linkedListHead))


  fmt.Println("Simple Program Employee")
  fmt.Println("---------------------")

  for {
    exitStatus := 0;
    printMenus()
    fmt.Print("Choose menu: ")

    readerOption := bufio.NewReader(os.Stdin)
    selectedOption, _, err := readerOption.ReadRune()

    if err != nil {
      fmt.Println(err)
    }

    switch selectedOption {
    case '1':
      if countLinkedList(&linkedListHead) > 5 {
        fmt.Println("ERROR: total employee can't more than 5")
        break
      }

      handleAddExployee(&linkedListHead)
      break
    case '2':
      if countLinkedList(&linkedListHead) == 0 {
        fmt.Println("Sorry, no employee yet!")
        break
      }
      fmt.Println("List Employees:")
      printAllEmployees(&linkedListHead)
      break
    case '3':
      handleDeleteEmployeeByID(&linkedListHead)
      break
    case '4':
      handleDeleteAllEmployees(&linkedListHead)
      break
    case '5':
      fmt.Println("Program Exit, Thank you!")
      exitStatus = 1
      break
    default:
      fmt.Println("ERROR: Option unavailable")
    }

    if exitStatus == 1 {
      break;
    }
  }
}

func printMenus() {
  fmt.Println("----------------------")
  fmt.Println("Menus:")
  // menus := [...]string{"add", "show all", "delete by id", "delete all", "exit"}
  menus := map[int]string{
    1: "Add Employee",
    2: "Show Employees",
    3: "Delete Employee",
    4: "Delete All Employees",
    5: "Exit",
  }

  for key, value := range menus {
    fmt.Println(key, value)
  }
}

func findLastNodePtr(ptrHead *Node) *Node {
	lastPtr := ptrHead

	for lastPtr.next != nil {
		lastPtr = lastPtr.next
	}

	return lastPtr
}

func countLinkedList(ptrHead *Node) int {
  count := 0
	currNode := ptrHead

	for currNode.next != nil {
		currNode = currNode.next
    count += 1
	}

	return count
}

func printAllEmployees(ptrHead *Node) {
	currNode := ptrHead

	for currNode.next != nil {
		currNode = currNode.next
    employee := currNode.value

    fmt.Println("------------------------------------------------")
    fmt.Println("Employee ID: ", employee.id)
    fmt.Println("Full Name: ", employee.fullName)
    fmt.Println("Birth Place: ", employee.birthPlace)
    fmt.Println("Birth Day: ", employee.birthDay)
    fmt.Println("Position: ", employee.position)
	}
}

func insert(headNode *Node, newNode *Node) {
	lastNode := findLastNodePtr(headNode)
  lastNode.next = newNode
}

func findPreviousNode(headNode *Node, targetNode *Node) *Node {
  currentNode := headNode

  for {
    if (currentNode.next == targetNode) {
      return currentNode
    }

		currentNode = currentNode.next
	}
}

func removeNode(headNode *Node, targetNode *Node) {
  prev := findPreviousNode(headNode, targetNode)
  prev.next = targetNode.next
}

func handleAddExployee(headNode *Node) {
  fmt.Print("Employee ID: ")
  id := askInput()

  fmt.Print("Employee Full Name: ")
  fullName := askInput()
  
  fmt.Print("Employee Birth Place: ")
  birthPlace := askInput()
  
  fmt.Print("Employee Birth Day: ")
  birthDay := askInput()
  
  fmt.Print("Employee Position: ")
  position := askInput()
  

  newEmployee := Employee{
    id: id,
    fullName: fullName,
    birthPlace: birthPlace,
    birthDay: birthDay,
    position: position,
  }

  if err := validateEmployee(&newEmployee); err != nil {
    fmt.Println(err)
    return
  }

  newNode := Node{value: newEmployee}
  insert(headNode, &newNode)
}

func handleDeleteAllEmployees(headNode *Node) {
  headNode.next = nil
}

func handleDeleteEmployeeByID(headNode *Node) {
  fmt.Print("Employee ID: ")
  id := askInput()

  currNode := headNode
  var targetNode *Node

	for currNode.next != nil {
		currNode = currNode.next
    if currNode.value.id == id {
      targetNode = currNode
    }
	}

  if targetNode == nil {
    return
  }

  removeNode(headNode, targetNode)
}

func validateEmployee(employee *Employee) (error) {
  if len(employee.id) > 5 {
    return fmt.Errorf("Max lenght for id is 5")
  }
  if len(employee.birthPlace) > 30 {
    return fmt.Errorf("Max lenght for birth place is 30")
  }
  if len(employee.fullName) > 30 {
    return fmt.Errorf("Max lenght for full name is 30")
  }
  if len(employee.position) > 50 {
    return fmt.Errorf("Max lenght for birth place is 50")
  }

  return nil
}

func askInput() string {
  reader := bufio.NewReader(os.Stdin)

  text, _ := reader.ReadString('\n')
  // convert CRLF to LF
  text = strings.Replace(text, "\n", "", -1)

  return text
}
