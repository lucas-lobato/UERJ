Here is a simple flow chart:

```mermaid
graph LR
a((*))-->0;
0((0)) -- < -->1((1));
1 -- = -->2((2)) --> r["retorna (relop,LE)"];
1 -- > -->3((3)) --> p["retorna (relop,NE)"];
1 -- outro -->4((4)) --> q["retorna (relop,LT)"];
0 -- > -->6((6));
6 -- = -->7((7)) --> t["retorna (relop,GE)"];
6 -- > -->8((8)) --> u["retorna (relop,GT)"];
0 -- = -->5((5)) --> s["retorna (relop,EQ)"];
```