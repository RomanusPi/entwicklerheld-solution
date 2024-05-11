class ParityBitPython:
    @staticmethod
    def validate_client_number(client_number: str) -> bool:

        if len(client_number) != 10:
            return False
        if client_number.isdigit() == False:
            return False    

        #check pairity bit
        binary_client_number = bin(int(client_number))[2:]    
      
        count = 0
        for digit in binary_client_number:
            if digit == "1":
                count += 1

        if count % 2 != 0:
            return False
        return True   
