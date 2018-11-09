class TreeNode:
	def __init__(self, x, l=None, r=None):
		self.val=x
		self.left=l
		self.right=r

class Solution:
	def rob(self,root):
		return self.helper(root)[1]

	def helper(self,cur):
		if not cur:
			return (0,0)
		L=self.helper(cur.left)
		R=self.helper(cur.right)
		sumA=L[0]+R[0]+cur.val
		sumB=L[1]+R[1]
		return (sumB,max(sumB,sumA))


n5=TreeNode(1)
n4=TreeNode(3)
n3=TreeNode(3,None,n5)
n2=TreeNode(2,None,n4)
n1=TreeNode(3,n2,n3)
s=Solution()
res=s.rob(n1)
print(res)

