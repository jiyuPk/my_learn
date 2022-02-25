package token

type TypeName = string

type Token struct {
	Type    TypeName
	Literal string
}

var keywords = map[string]TypeName{
	"fn":     FUNC,
	"let":    LET,
	"true":   TRUE,
	"false":  FASLE,
	"if":     IF,
	"else":   ELSE,
	"return": RETURN,
}

const (
	ILLEGAL = "ILLEGAL"
	EOF     = "EOF"

	IDENT = "IDENT"
	INT   = "INT"

	ASSIGN   = "="
	PLUS     = "+"
	MINUS    = "-"
	BANG     = "!"
	ASTERISK = "*"
	SLASH    = "/"
	EQ       = "=="
	NOT_EQ   = "!="

	COMMA     = ","
	SEMICOLON = ";"

	LPAREN = "("
	RPAREN = ")"
	LBRACE = "{"
	RBRACE = "}"
	LT     = "<"
	GT     = ">"

	FUNC   = "FUNC"
	LET    = "LET"
	TRUE   = "TRUE"
	FASLE  = "FALSE"
	IF     = "IF"
	ELSE   = "ELSE"
	RETURN = "RETURN"
)

func LookupIdent(ident string) TypeName {
	if tok, ok := keywords[ident]; ok {
		return tok
	}
	return IDENT
}
