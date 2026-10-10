# cook your dish here
def Kadane(arr):
  current_total, max_total  = -float("inf"), -float("inf")
  start, end = 0, 0 
  temp_start = 0  
    
  for i in range(len(arr)):
    if current_total + arr[i] < arr[i]:
      current_total = arr[i]
      temp_start = i  
    else: 
      current_total += arr[i]
        
    if max_total < current_total: 
      max_total = current_total
      start = temp_start  
      end = i  
    
  return max_total, start, end
  
def maxSum2D(matrix, r, c, r2, c2):
  rows = len(matrix)
  cols = len(matrix[0])
  max_sum = float('-inf')
  
  final_left, final_right = 0, 0
  final_top, final_bottom = 0, 0
  for left in range(c, c2 + 1):
    sums = [0] * rows 
        
    for right in range(left, c2 + 1):
        for row in range(r, r2 + 1):
            sums[row] += matrix[row][right]
        
        res = Kadane(sums[r:r2 + 1])
        if res[0] > max_sum:
            max_sum = res[0]
            final_top = res[1] + r
            final_bottom = res[2] + 2
            final_left = left
            final_right = right
            
  return max_sum
  

TS = input().split(" ")
T = list(map(int,TS))
rows = T[0]
col = T[1]
q = T[2]

matrix = [] 
for i in range(rows):   
    matrix.append(list(map(int,input().split(" ")))) 

for i in range(q):
    RC = list(map(int,input().split(" ")))
    print(maxSum2D(matrix, RC[0] - 1, RC[1] - 1, RC[2] - 1, RC[3] - 1))
    