knightMoves = [[-1,-2], [-2,-1], [-2,1], [-1,2], [1,2], [2,1], [2,-1], [1,-2]]
positionLetter = ['a','b','c','d','e','f','g','h']

def isValid(i,j):
    if i>=0 and i<8 and j>=0 and j<8:
        return True
    return False

def BFS(i,j,x,y):
    if i==x and j==y:
        return 0
    visited = set()
    queue = [(i,j,0)]
    while queue:
        i,j,moves = queue.pop(0)
        for move in knightMoves:
            newi = i+move[0]
            newj = j+move[1]
            if newi==x and newj==y:
                return moves+1
            if isValid(newi, newj) and (newi,newj) not in visited:
                visited.add((newi,newj))
                queue.append((newi,newj,moves+1))

    return -1
    

while True:
    try:
        x,y = map(str,input().split())
        i = positionLetter.index(x[0])
        j = int(x[1])-1
        a = positionLetter.index(y[0])
        b = int(y[1])-1

        print("To get from",x,"to",y,"takes",BFS(i,j,a,b),"knight moves.")
    except EOFError:
        break