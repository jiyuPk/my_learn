package main

import (
	"fmt"
	"interpreter/repl"
	"os"
	user2 "os/user"
)

func main() {
	user, err := user2.Current()
	if err != nil {
		panic(err)
	}

	fmt.Printf("Hello %s!\n", user.Username)
	fmt.Printf("type commands\n")
	repl.Start(os.Stdin, os.Stdout)
}
