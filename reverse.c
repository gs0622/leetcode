struct list {
	int data;
	struct list *next;	
};

struct list *reverse(struct list *head) {
	struct list *cur=head, *tmp=NULL;
	while (cur->next) {
		head = cur->next;	// head steps one
		cur->next = tmp;	// reverse link
		tmp = cur;		// tmp steps one (tmp to cur)
		cur = head;		// cur steps one (cur to head)
	}
	cur->next = tmp;
	return head;
}

void reverse2(struct list **href, struct list *prev) {
	if (*href == NULL) return;
	reverse2(&((*href)->next), *href);
	struct list *cur = *href;
	cur->next = prev;
}

