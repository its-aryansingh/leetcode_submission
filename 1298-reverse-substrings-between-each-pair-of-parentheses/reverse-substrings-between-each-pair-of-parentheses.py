class Solution:
    def reverseParentheses(self, s: str) -> str:
        stack = []
        
        for char in s:
            if char == ')':
                # Pop characters until we find the matching '('
                curr = []
                while stack and stack[-1] != '(':
                    curr.append(stack.pop())
                
                # Pop the open parenthesis '(' itself
                if stack:
                    stack.pop()
                
                # Push the reversed characters back onto the stack
                # (Since we popped them, they are already reversed!)
                stack.extend(curr)
            else:
                # Push letters and '(' onto the stack
                stack.append(char)
                
        return "".join(stack)
