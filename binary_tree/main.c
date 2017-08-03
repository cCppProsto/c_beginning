#include <stdio.h>
#include "../../tools_src/binary_tree.h"

void test_tree_rr()
{
  sBinTree tree;
  bt_init(&tree);
  sLeaf leaf;

  leaf.key = 1;  bt_insert(&tree, &leaf);
  //     1

  leaf.key = 2;  bt_insert(&tree, &leaf);
  //     1
  //       2

  leaf.key = 3;  bt_insert(&tree, &leaf);
  //       1
  //   N       2
  //         N   3
  // rr rotation

  // запоминаем правый узел корня - root->right[2] ( NULL <- 2 -> 3) - tmp
  // правому узлу корня присваиваем левый узел tmp->left
  // изменяем корень
  //             1
  //          N     N
  //

  // берем узел который сохранили (NULL <- 2 -> 3)
  //            2
  //          N   3
  //
  // и левому узлу присваиваем корень
  //            2
  //          1   3
  //
  // присваиваем корню этот узел


  leaf.key = 4;  bt_insert(&tree, &leaf);
  //            2
  //          1   3
  //                4

  leaf.key = 5;  bt_insert(&tree, &leaf);
  //            2
  //          1   3
  //                4
  //                  5

  // в силу рекурсии балансировка на этом шаге будет работать для корня 3
  // так как поиск узла для добавления идет рекурсивно, то
  // после добавления идет завершение всех рекурсивных функций
  // после отработки рекурсивной функции вставки, происходит сравнение
  // глубины правого и левого узла
  // на этом примере, после добавления значения 5, завершается вставка
  // возвращаемся по рекурсии обратно, и после вставки идет проверка для узла 4,
  // для узла 4 глубина правого и левого поддерева допустима,
  // идет следующий возврат, и проверяем для узла 3
  // для узла 3 глубина левого и правого поддерева недопустима,
  // поэтому балансируем узел 3, после балансировки и возврата к корню 2,
  // глубина правого и левого поддерева допустима

  // rr rotation
  // запоминаем правый узел корня - root->right[4] ( NULL <- 4 -> 5) - tmp
  // правому узлу корня присваиваем левый узел tmp->left
  // изменяем корень
  //             3
  //          N     N
  //

  // берем узел который сохранили (NULL <- 4 -> 5 )
  //            4
  //          N   5
  //
  // и левому узлу присваиваем корень
  //            4
  //          3   5
  //
  // присваиваем корню этот узел
  //             2
  //          1      4
  //               3   5


  leaf.key = 6;  bt_insert(&tree, &leaf);
  //             2
  //          1      4
  //               3   5
  //                     6

  leaf.key = 7;  bt_insert(&tree, &leaf);
  //             2
  //          1      4
  //               3   5
  //                     6
  //                       7

  // rr rotation
  // запоминаем правый узел корня - root->right[5] ( NULL <- 6 -> 7) - tmp
  // правому узлу корня присваиваем левый узел tmp->left
  // изменяем корень
  //             5
  //          N     N
  //

  // берем узел который сохранили (NULL <- 6 -> 7 )
  //            6
  //          N   7
  //
  // и левому узлу присваиваем корень
  //            6
  //          5   7
  //
  // присваиваем корню этот узел
  //             2
  //          1       4
  //                3     6
  //                    5   7

  // для узла 2 и одновременно корня(помним про рекурсию),
  // глубина левого и правого не допустимы
  // для этого узла выполняется все тот-же поворот

  // rr rotation
  // запоминаем правый узел корня - root->right[2] ( 3 <- 4 -> 6 -> ...) - tmp
  // правому узлу корня присваиваем левый узел tmp->left
  // изменяем корень
  //             2
  //          1     3
  //

  // берем узел который сохранили (3 <- 4 -> 6 )
  //             4
  //          3     6
  //              5   7

  // и левому узлу присваиваем корень
  //              4
  //         2         6
  //       1   3     5   7

  leaf.key = 8;  bt_insert(&tree, &leaf);
  leaf.key = 9;  bt_insert(&tree, &leaf);
  leaf.key = 10;  bt_insert(&tree, &leaf);
  leaf.key = 11;  bt_insert(&tree, &leaf);
  leaf.key = 12;  bt_insert(&tree, &leaf);
  //                   8
  //          4              10
  //       2     6         9    11
  //     1   5     7               12

  if(bt_search(&tree, 1) != NULL)
    printf("1 was founded\n");
  else
    printf("1 not founded\n");

  if(bt_search(&tree, 2) != NULL)
    printf("2 was founded\n");
  else
    printf("2 not founded\n");

  if(bt_search(&tree, 3) != NULL)
    printf("3 was founded\n");
  else
    printf("3 not founded\n");

  if(bt_search(&tree, 4) != NULL)
    printf("4 was founded\n");
  else
    printf("4 not founded\n");

  if(bt_search(&tree, 5) != NULL)
    printf("5 was founded\n");
  else
    printf("5 not founded\n");

  bt_destroy(&tree);
}

void test_tree_2()
{
  sBinTree tree;
  bt_init(&tree);
  sLeaf leaf;

  leaf.key = 2;  bt_insert(&tree, &leaf);
  //     2

  leaf.key = 5;  bt_insert(&tree, &leaf);
  //     2
  //       5

  leaf.key = 1;  bt_insert(&tree, &leaf);
  //      2
  //    1   5

  leaf.key = 4;  bt_insert(&tree, &leaf);
  //      2
  //   1     5
  //       4

  leaf.key = 3;  bt_insert(&tree, &leaf);
  //       2
  //   1      5
  //        4
  //      3

  // ll rotation для корня [5]
  //
  // запоминаем левый узел корня - root->right[5] ( 3 <- 4 -> N) - tmp
  // левому узлу корня присваиваем правый узел tmp->left
  // изменяем корень
  //             2
  //          1    [5]
  //              N   N
  //

  // берем узел который сохранили (3 <- 4 -> NULL)
  //            4
  //          3   N
  //
  // и правому узлу присваиваем корень
  //            4
  //          3   5

  //
  //            2
  //          1    4
  //             3    5
  // присваиваем корню этот узел


  bt_destroy(&tree);
}


void test_in_order_print()
{
  sBinTree tree;

  bt_init(&tree);
  sLeaf leaf;

  leaf.key = 8;
  bt_insert(&tree, &leaf);
  //  8

  leaf.key = 12;
  bt_insert(&tree, &leaf);
  //     8
  //       12

  leaf.key = 5;
  bt_insert(&tree, &leaf);
  //       8
  //     5   12

  leaf.key = 3;
  bt_insert(&tree, &leaf);
  //       8
  //     5   12
  //   3

  leaf.key = 2;
  bt_insert(&tree, &leaf);
  //        8
  //     3    12
  //   2   5

  leaf.key = 4;
  bt_insert(&tree, &leaf);
  //          8
  //     3       12
  //  2     5
  //      4

  // left - right rotation
  //
  // корень - [8]
  // запоминаем левый узел корня root->right[8] ( 2 <- 3 -> 5 ... )
  // 1) выполняем rr_rotation для этого корня [3]
  //  rr_rotation для ( 2 <- 3 -> 5 ... )
  //      3
  //   2     5
  //       4
  // получаем
  //         5
  //       3
  //     2   4
  //
  // присваеваем это поддерево левому узлу корня [8]
  //         8
  //      5     12
  //    3
  //  2   4

  // 2) ll_rotation для корня [8]
  //
  // получаем
  //          5
  //      3     8
  //    2   4     12

  leaf.key = 6;
  leaf.value.data = 6;
  bt_insert(&tree, &leaf);

  leaf.key = 7;
  leaf.value.data = 7;
  bt_insert(&tree, &leaf);

  leaf.key = 11;
  leaf.value.data = 11;
  bt_insert(&tree, &leaf);

  leaf.key = 10;
  leaf.value.data = 10;
  bt_insert(&tree, &leaf);

  leaf.key = 15;
  leaf.value.data = 15;
  bt_insert(&tree, &leaf);

  leaf.key = 14;
  leaf.value.data = 14;
  bt_insert(&tree, &leaf);

  leaf.key = 16;
  leaf.value.data = 16;
  bt_insert(&tree, &leaf);

  bt_in_order_print(&tree);

  bt_destroy(&tree);
}

void test_pre_order_print()
{
  sBinTree tree;

  bt_init(&tree);
  sLeaf leaf;

  leaf.key = 8;
  leaf.value.data = 8;
  bt_insert(&tree, &leaf);

  leaf.key = 12;
  leaf.value.data = 12;
  bt_insert(&tree, &leaf);

  leaf.key = 5;
  leaf.value.data = 5;
  bt_insert(&tree, &leaf);

  leaf.key = 3;
  leaf.value.data = 3;
  bt_insert(&tree, &leaf);

  leaf.key = 2;
  leaf.value.data = 2;
  bt_insert(&tree, &leaf);

  leaf.key = 4;
  leaf.value.data = 4;
  bt_insert(&tree, &leaf);

  leaf.key = 6;
  leaf.value.data = 6;
  bt_insert(&tree, &leaf);

  leaf.key = 7;
  leaf.value.data = 7;
  bt_insert(&tree, &leaf);

  leaf.key = 11;
  leaf.value.data = 11;
  bt_insert(&tree, &leaf);

  leaf.key = 10;
  leaf.value.data = 10;
  bt_insert(&tree, &leaf);

  leaf.key = 15;
  leaf.value.data = 15;
  bt_insert(&tree, &leaf);

  leaf.key = 14;
  leaf.value.data = 14;
  bt_insert(&tree, &leaf);

  leaf.key = 16;
  leaf.value.data = 16;
  bt_insert(&tree, &leaf);

  bt_pre_order_print(&tree);

  bt_destroy(&tree);
}

void test_post_order_print()
{
  sBinTree tree;

  bt_init(&tree);
  sLeaf leaf;

  leaf.key = 8;
  leaf.value.data = 8;
  bt_insert(&tree, &leaf);

  leaf.key = 12;
  leaf.value.data = 12;
  bt_insert(&tree, &leaf);

  leaf.key = 5;
  leaf.value.data = 5;
  bt_insert(&tree, &leaf);

  leaf.key = 3;
  leaf.value.data = 3;
  bt_insert(&tree, &leaf);

  leaf.key = 2;
  leaf.value.data = 2;
  bt_insert(&tree, &leaf);

  leaf.key = 4;
  leaf.value.data = 4;
  bt_insert(&tree, &leaf);

  leaf.key = 6;
  leaf.value.data = 6;
  bt_insert(&tree, &leaf);

  leaf.key = 7;
  leaf.value.data = 7;
  bt_insert(&tree, &leaf);

  leaf.key = 11;
  leaf.value.data = 11;
  bt_insert(&tree, &leaf);

  leaf.key = 10;
  leaf.value.data = 10;
  bt_insert(&tree, &leaf);

  leaf.key = 15;
  leaf.value.data = 15;
  bt_insert(&tree, &leaf);

  leaf.key = 14;
  leaf.value.data = 14;
  bt_insert(&tree, &leaf);

  leaf.key = 16;
  leaf.value.data = 16;
  bt_insert(&tree, &leaf);

  bt_post_order_print(&tree);

  bt_destroy(&tree);
}

int main()
{
  //test_tree_rr();
  //test_tree_2();


  /*       ______8______
          /             \
       __5__            _14__
      /     \          /     \
    _3_      6_       11      15__
   /   \       \     /  \         \
  2     4       7   10  12        16 */
  // левое поддерево, вершина, правое поддерево
  // элементы в порядке возрастания
  test_in_order_print();


  /*       ______8______
          /             \
       __5__            _14__
      /     \          /     \
    _3_      6_       11      15__
   /   \       \     /  \         \
  2     4       7   10  12        16 */
  // вершина, левое поддерево, правое поддерево
  // элементы как в дереве
  test_pre_order_print();


  /*       ______8______
          /             \
       __5__            _14__
      /     \          /     \
    _3_      6_       11      15__
   /   \       \     /  \         \
  2     4       7   10  12        16 */
  // левое поддерево, правое поддерево, вершина
  // элементы в обратном порядке как в дереве
  test_post_order_print();

  return 0;
}





