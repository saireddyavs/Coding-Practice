Node *merge(Node *a, Node *b)
{
    if (a == NULL)
    {
        return b;
    }

    if (b == NULL)
    {
        return a;
    }

    Node *result;
    if (a->data > b->data)
    {
        result = b;
        result->bottom = merge(a, b->bottom);
    }
    else
    {
        result = a;
        result->bottom = merge(a->bottom, b);
    }
    return result;
}
/*  Function which returns the  root of
    the flattened linked list. */
Node *flatten(Node *root)
{
    // Your code here

    if (root == NULL || root->next == NULL)
        return root;

    root->next = flatten(root->next);

    root = merge(root, root->next);
    return root;
}