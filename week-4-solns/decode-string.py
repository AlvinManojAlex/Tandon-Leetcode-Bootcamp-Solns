class Solution:
    def decodeString(self, s: str) -> str:
        
        stack = []
        currNumber = 0
        currString = ""

        for x in s:

            if x == '[':
                stack.append(currString)
                stack.append(currNumber)
                currString = ""
                currNumber = 0

            elif x == ']':
                num = stack.pop()
                prevString = stack.pop()
                currString = prevString + (num * currString)

            elif x.isdigit():
                currNumber = currNumber * 10 + int(x)

            else:
                currString += x

        
        return currString