from string import *

class program_struct:
    def __init__(self,program, var, begin, end, iff, then, elsee, whilee, do, intt) -> None:
        self.program = program
        self.var = var
        self.begin = begin
        self.end = end
        self.iff = iff
        self.then = then
        self.elsee = elsee
        self.whilee = whilee
        self.do = do
        self.intt = intt
    
def datainput():
    programa = "program correto; int a, b; begin a:=-2; b:=10 begin if (a<1) then b:=1 end end."
    return programa

def analisa():
    programa = datainput()
    begin = 0
    end = 0
    letters = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r'
               ,'s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J'
               ,'K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
    for i in programa:
        if i in letters:
            print("letter",i)
                
analisa()