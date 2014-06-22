/*
 * 编译方法
 * gcc -D__KERNEL__ -I/usr/src/linux-headers-`uname -r`/include \
 * list.c -o list
 *
 * 用户程序使用内核提供的链表功能示例
 *   把程序参数保存到链表中
 */

#include <stdio.h>
#include <linux/list.h>

#ifndef offsetof
#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
#endif

#define container_of(ptr, type, member) ({ \
        const typeof( ((type *)0)->member ) *__mptr = (ptr); \
        (type *)( (char *)__mptr - offsetof(type,member) );})


struct my_list_node {
    char *data;
    struct list_head list;
};

int main(int argc, char *argv[])
{
    int i;
    int result = 0;
    struct my_list_node *node = NULL;
    struct my_list_node *tmp = NULL;
    struct list_head *pos = NULL;

    LIST_HEAD(head);
    for (i = 1; i < argc; i++) {
        node = malloc(sizeof(struct my_list_node));
        if (node == NULL) {
            fprintf(stderr, "malloc node failed\n");
            result = -2;
            goto exit;
        }

        node->data = argv[i];
        list_add_tail(&node->list, &head);
    }

    if (list_empty(&head)) {
        fprintf(stderr, "none args\n");
        result = -1;
        goto exit;
    }

    /*
     * 遍历链表，再获取entry
     */
    list_for_each(pos, &head) {
        node = list_entry(pos, struct my_list_node, list);
        fprintf(stdout, "you input: %s\n", node->data);
    }

exit:
    /*
     * 直接遍历entry
     * safe后缀根据list.h注释可以用于删除
     */
    list_for_each_entry_safe(node, tmp, &head, list) {
        list_del(&node->list);
        fprintf(stdout, "freeing input: %s\n", node->data);
        free(node);
    }
    if (list_empty(&head))
        fprintf(stdout, "list is empty\n");
    else
        fprintf(stdout, "something was wrong\n");

    return result;
}
