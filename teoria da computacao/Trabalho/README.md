## Expressão regular
    
    ``` 
        letra = [a-zA-z]
        palavra = letra | letra?
        digito = [0-9]
        numero = digito | digito?
        identificador = letra | (letra|digito)?
        log = {<,>,=}
        oplogic = log | log?
        simbolo = {+,-,*,div}
    ```

## Diagrama de estados dos operadores lógicos:

```mermaid
stateDiagram-v2
    direction LR
    [*] --> 0
    0 --> 1: <
    0 --> 5: =
    0 --> 6: >
    0 --> 7: 
    note left of 7
        :
    end note
    1 --> 2: =
    1 --> 3: >
    1 --> 4: outro
    note right of 2
        retorna (relop,LE)
        estado = 0
    end note
    note right of 3
        retorna (relop,NE)
        estado = 0
    end note
    note right of 4
        retorna (relop,LT)
        estado = 0
    end note
    note right of 5
        retorna (relop,EQ)
        estado = 0
    end note
    note right of 7
        retorna (<,)
        estado = 0
    end note
    6 --> 8: =
    6 --> 9: outro
    note right of 8
        retorna (relop,GE)
        estado = 0
    end note
    note right of 9
        retorna (relop,GT)
        estado = 0
    end note
```
## digitorama de estado do paranteses
```mermaid
stateDiagram-v2
direction LR
[*] --> 0
0 --> 10
10 --> 11: (
10 --> 12: )
note right of 11
    retorna <(,>
    estado = 0
end note
note right of 12
    retorna <),>
    estado = 0
end note    
```

```mermaid
stateDiagram-v2
direction LR
[*] --> 13
13 --> 14: .
note right of 14
    retorna <., >
    estado = 0
end note
13 --> 15
note right of 15
retorna <;, >
    estado = 0
end note
note left of 15
    ;
end note
13 --> 16: ,
note right of 16
    retorna <,>
    estado = 0
end note
13 --> 17: p
17 --> 18: r
18 --> 19: o
19 --> 20: g
20 --> 21: r
21 --> 22: a
22 --> 23: m
note right of 23
retorna <"program", >
    estado = 0
end note
13 --> 24: b
24 --> 25: e
25 --> 26: g
26 --> 27: i
27 --> 28: n
note right of 28
retorna <"begin", >
    estado = 0
end note
13 --> 31: digitoito
31 --> 31: digitoito
note right of 31
retorna <'num", numero>
    estado = 0
end note
13 --> 32: i
32 --> 33: f
note right of 33
    retorna <'if", >
    estado = 0
end note
32 --> 34: n
note right of 34 
retorna <'int", >
    estado = 0
end note
13 --> 35: d
35 --> 43: o
note right of 43
retorna <'do", >
    estado = 0
end note
35 --> 40: i
note right of 40
retorna <'div", >
    estado = 0
end note
13 --> 44: v
44 --> 45: a
45 --> 46: r
note right of 46
retorna <'var", >
    estado = 0
end note
13 --> 47: e
47 --> 48: n
48 --> 49: d
note right of 49
retorna <'end", >
    estado = 0
end note
47 --> 50: l
50 --> 51: s
51 --> 52: e 
note right of 52
retorna <'else", >
    estado = 0
end note
13 --> 53: t
53 --> 54: h
54 --> 55: e
55 --> 56: n
note right of 56
    retorna <'then', >
    estado = 0
end note

13 --> 57: w
57 --> 58: h
58 --> 59: i
59 --> 60: l
60 --> 61: e
note right of 61
    retorna <'while', >
    estado = 0
end note

```
## Diagram de operadores aritmeticos
```mermaid
stateDiagram-v2
direction LR

[*] --> 36
36 --> 37: +
note right of 37
retorna <oparit, +>
    estado = 0
end note
36 --> 38: -
note right of 38
retorna <oparit, ->
    estado = 0
end note
36 --> 39: *
note right of 39
retorna <oparit, *>
    estado = 0
end note
36 --> 40: d
note right of 40
    estado = 0
end note

```
## Diagram de identificador

```mermaid
stateDiagram-v2
direction LR

[*] --> 62: letra
62 --> 62: letra U digitoito
note right of 62
    retorna <'id', identificador>
    estado = 0
end note
```