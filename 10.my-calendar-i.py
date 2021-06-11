import bisect 
class MyCalendar:
    
    def __init__(self):
        self.cal=[]
       
    
    def book(self, start: int, end: int) -> bool:
        for a in self.cal:
            if (max(a[0], start) < min(a[1], end)):
                return False
        self.cal.append([start, end])
        return True;

        
