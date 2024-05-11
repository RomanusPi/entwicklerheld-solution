import random


class CellularAutomatonImpl:
    def __init__(self, index: int, width: int = 10) -> None:
        """
        Constructs a cellular automaton based on the index
        of the Wolfram Code using a given width for the number of cells.
        :param index: 8 bit representing the index of the automaton
        :param width: number of cells
        """
        self.cells = []
        self.index = index
        self.width = max(10, width)
        self.randomize()
    
    def randomize(self) -> None:
        """
        Generates a random state with the specified number of cells.
        """
        self.cells = []
        r = random.getrandbits(self.width)
        while r > 0:
            self.cells.append(r % 2 == 1)
            r = r >> 1
    
    def preset(self, s: str) -> None:
        """
        Sets the current state to a given string.
        A blank character represents the state false,
        otherwise true
        :param s: string representing the state
        """
        self.width = max(self.width, len(s))
        self.cells = []
        for x in s:
            self.cells.append(x != " ")
    
    def get_cell(self, i: int) -> int:
        """
        Provides the current state of the i-th cell
        :param i: number of the cell
        :return: state of the i-th cell 0 or 1
        """
        if 0 <= i < len(self.cells):
            return self.cells[i]
        return 0
    
    def has_rule(self, i: int) -> bool:
        """
        Calculates whether the i-th bit for rule i in the
        index of the automaton is set.
        :param i: number of the rule/bit
        :return: true when the i-th bit of the binary index is 1
        """
       
        return (self.index & (1 << i)) != 0 
        
   
    
    def evolve(self) -> None:
        """
        Calculates the next state for each cell based on the
        current own state and the neighbors.
        """
        build_Cells=[]
        print("selfcelss:",self.cells)
        print("index", self.index)
        print(self.get_rule_set())
        
        self.cells.append( False)

        for s in range(len(self.cells)-1): 
                     
            neighborsIndex = (int(self.cells[ s - 1 ]) * 4 + 
            int(self.cells[ s ]) * 2 + 
            int(self.cells[(s + 1) % len(self.cells)]))
            
          
                        
            if self.has_rule(neighborsIndex):
                build_Cells.append(True)
            else:
                build_Cells.append(False)
            
     
    
        self.cells = build_Cells  
        print(self.state()) 
        print(self.cells) 
      
        
       
       
    
    def run(self, n: int) -> None:
        """
        Evolves the automaton n times and prints the state
        of all cells each time.
        :param n: number of evolutions
        """
        for i in range(n):
            self.evolve()
            print(self.state())
    
    def get_rule_set(self) -> set:
        """
        Provides the set of rules as numbers represented
        by the index of the automaton
        :return: the set of rules as numbers
        """
        rules = set()
        for i in range(8):
            if self.has_rule(i):
                rules.add(i)
        return rules
    
    def state(self) -> str:
        """
        Provides the current state of each cell as a string.
        :return: the state as a string
        """
        s = ""
        for b in self.cells:
            if b:
                s += "█"
            else: 
                s += " "
        return s
