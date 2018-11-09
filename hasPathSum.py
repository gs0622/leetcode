class TreeNode:
	def __init__(self, x, l=None, r=None):
		self.val=x
		self.left=l
		self.right=r

class Solution:
	def hasPathSum(self,root,sum):
        """
        :type root: TreeNode
        :type sum: int
        :rtype: bool
        """
		if not root:
			return False
		if root.val==sum and not root.left and not root.right:
			return True
		return self.hasPathSum(root.left, sum-root.val) or self.hasPathSum(root.right, sum-root.val)

n2=TreeNode(2)
n1=TreeNode(1,n2,None)
s=Solution()
res=s.hasPathSum(n1,1)
print(res)
