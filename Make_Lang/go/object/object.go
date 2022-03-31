package object

import (
	"bytes"
	"fmt"
	"lang/ast"
	"strings"
)

type Type string

const (
	IntegerObj     = "Integer"
	BooleanObj     = "Boolean"
	NullObj        = "Null"
	ReturnValueObj = "ReturnValue"
	ErrorObj       = "Error"
	FunctionObj    = "Function"
)

type Object interface {
	Type() Type
	Inspect() string
}

type Integer struct {
	Value int64
}

func (i *Integer) Type() Type      { return IntegerObj }
func (i *Integer) Inspect() string { return fmt.Sprintf("%d", i.Value) }

type Boolean struct {
	Value bool
}

func (b *Boolean) Type() Type      { return BooleanObj }
func (b *Boolean) Inspect() string { return fmt.Sprintf("%t", b.Value) }

type Null struct{}

func (n *Null) Type() Type      { return NullObj }
func (n *Null) Inspect() string { return "null" }

type ReturnValue struct {
	Value Object
}

func (rv *ReturnValue) Type() Type      { return ReturnValueObj }
func (rv *ReturnValue) Inspect() string { return rv.Value.Inspect() }

type Error struct {
	Message string
}

func (e *Error) Type() Type      { return ErrorObj }
func (e *Error) Inspect() string { return "ERROR: " + e.Message }

type Function struct {
	Parameters []*ast.Identifier
	Body       *ast.BlockStatement
	Env        *Environment
}

func (f *Function) Type() Type { return FunctionObj }
func (f *Function) Inspect() string {
	var out bytes.Buffer

	var params []string
	for _, p := range f.Parameters {
		params = append(params, p.String())
	}

	out.WriteString("fn")
	out.WriteString("(")
	out.WriteString(strings.Join(params, ", "))
	out.WriteString(") {\n")
	out.WriteString(f.Body.String())
	out.WriteString("\n}")

	return out.String()
}
