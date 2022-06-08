package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	s := strings.Split(strings.ReplaceAll(strings.ReplaceAll(scanner.Text(), " ", ""), ",", "."), ";")
	a, _ := strconv.ParseFloat(s[0], 64)
	b, _ := strconv.ParseFloat(s[1], 64)

	fmt.Printf("%.4f", a/b)
}
