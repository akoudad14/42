<?php

/* CCDNForumForumBundle:Common/Layout/Sidebar/Partial:user_boards.html.twig */
class __TwigTemplate_6249f73497322a0f184dbb3809cb63e263c3068b1d5b977d6dd7a458692f7a5c extends Twig_Template
{
    public function __construct(Twig_Environment $env)
    {
        parent::__construct($env);

        $this->parent = false;

        $this->blocks = array(
        );
    }

    protected function doDisplay(array $context, array $blocks = array())
    {
        // line 1
        ob_start();
        // line 3
        $context["sidebar_categories"] = $this->env->getExtension('boardList')->boardList((isset($context["forumName"]) ? $context["forumName"] : null));
        // line 5
        if (twig_length_filter($this->env, (isset($context["sidebar_categories"]) ? $context["sidebar_categories"] : null))) {
            // line 6
            echo "<li>
\t\t\t<ul class=\"nav nav-pills nav-stacked\">";
            // line 8
            $context['_parent'] = (array) $context;
            $context['_seq'] = twig_ensure_traversable((isset($context["sidebar_categories"]) ? $context["sidebar_categories"] : null));
            foreach ($context['_seq'] as $context["_key"] => $context["sidebar_category"]) {
                // line 9
                if (twig_length_filter($this->env, $this->getAttribute((isset($context["sidebar_category"]) ? $context["sidebar_category"] : null), "boards"))) {
                    // line 10
                    if ((array_key_exists("category", $context) && ((isset($context["route"]) ? $context["route"] : null) == "ccdn_forum_user_category_show"))) {
                        // line 11
                        if (($this->getAttribute((isset($context["sidebar_category"]) ? $context["sidebar_category"] : null), "id") == $this->getAttribute((isset($context["category"]) ? $context["category"] : null), "id"))) {
                            // line 12
                            echo "<li class=\"active\">
\t\t\t\t\t\t\t\t\t<a href=\"";
                            // line 13
                            echo twig_escape_filter($this->env, $this->env->getExtension('routing')->getPath("ccdn_forum_user_category_show", array("categoryId" => $this->getAttribute((isset($context["sidebar_category"]) ? $context["sidebar_category"] : null), "id"), "forumName" => (isset($context["forumName"]) ? $context["forumName"] : null))), "html", null, true);
                            echo "\"
\t\t\t\t\t\t\t\t\t title=\"";
                            // line 14
                            echo twig_escape_filter($this->env, $this->getAttribute((isset($context["sidebar_category"]) ? $context["sidebar_category"] : null), "name"), "html", null, true);
                            echo "\">
\t\t\t\t\t\t\t\t\t\t<i class=\"glyphicon glyphicon-folder-open\"></i>";
                        } else {
                            // line 17
                            echo "<li>
\t\t\t\t\t\t\t\t\t<a href=\"";
                            // line 18
                            echo twig_escape_filter($this->env, $this->env->getExtension('routing')->getPath("ccdn_forum_user_category_show", array("categoryId" => $this->getAttribute((isset($context["sidebar_category"]) ? $context["sidebar_category"] : null), "id"), "forumName" => (isset($context["forumName"]) ? $context["forumName"] : null))), "html", null, true);
                            echo "\"
\t\t\t\t\t\t\t\t\t title=\"";
                            // line 19
                            echo twig_escape_filter($this->env, $this->getAttribute((isset($context["sidebar_category"]) ? $context["sidebar_category"] : null), "name"), "html", null, true);
                            echo "\">
\t\t\t\t\t\t\t\t\t\t<i class=\"glyphicon glyphicon-folder-open\"></i>";
                        }
                    } else {
                        // line 23
                        echo "<li>
\t\t\t\t\t\t\t\t\t<a href=\"";
                        // line 24
                        echo twig_escape_filter($this->env, $this->env->getExtension('routing')->getPath("ccdn_forum_user_category_show", array("categoryId" => $this->getAttribute((isset($context["sidebar_category"]) ? $context["sidebar_category"] : null), "id"), "forumName" => (isset($context["forumName"]) ? $context["forumName"] : null))), "html", null, true);
                        echo "\"
\t\t\t\t\t\t\t\t\t title=\"";
                        // line 25
                        echo twig_escape_filter($this->env, $this->getAttribute((isset($context["sidebar_category"]) ? $context["sidebar_category"] : null), "name"), "html", null, true);
                        echo "\">
\t\t\t\t\t\t\t\t\t\t<i class=\"glyphicon glyphicon-folder-open\"></i>";
                    }
                    // line 28
                    echo twig_escape_filter($this->env, $this->getAttribute((isset($context["sidebar_category"]) ? $context["sidebar_category"] : null), "name"), "html", null, true);
                    // line 29
                    echo "</a>
\t\t\t\t\t\t\t\t</li>

\t\t\t\t\t\t<li>
\t\t\t\t\t\t\t<ul class=\"nav nav-pills nav-stacked\">";
                    // line 34
                    $context['_parent'] = (array) $context;
                    $context['_seq'] = twig_ensure_traversable($this->getAttribute((isset($context["sidebar_category"]) ? $context["sidebar_category"] : null), "boards"));
                    foreach ($context['_seq'] as $context["_key"] => $context["sidebar_board"]) {
                        // line 35
                        if (array_key_exists("board", $context)) {
                            // line 36
                            if (($this->getAttribute((isset($context["sidebar_board"]) ? $context["sidebar_board"] : null), "id") == $this->getAttribute((isset($context["board"]) ? $context["board"] : null), "id"))) {
                                // line 37
                                echo "<li class=\"active\">
\t\t\t\t\t\t\t\t\t\t\t\t<a href=\"";
                                // line 38
                                echo twig_escape_filter($this->env, $this->env->getExtension('routing')->getPath("ccdn_forum_user_board_show", array("boardId" => $this->getAttribute((isset($context["sidebar_board"]) ? $context["sidebar_board"] : null), "id"), "forumName" => (isset($context["forumName"]) ? $context["forumName"] : null))), "html", null, true);
                                echo "\"
\t\t\t\t\t\t\t\t\t\t\t\t title=\"";
                                // line 39
                                echo twig_escape_filter($this->env, $this->getAttribute((isset($context["sidebar_board"]) ? $context["sidebar_board"] : null), "name"), "html", null, true);
                                echo "\">
\t\t\t\t\t\t\t\t\t\t\t\t\t<i class=\"glyphicon glyphicon-folder-open\"></i>";
                            } else {
                                // line 42
                                echo "<li>
\t\t\t\t\t\t\t\t\t\t\t\t<a href=\"";
                                // line 43
                                echo twig_escape_filter($this->env, $this->env->getExtension('routing')->getPath("ccdn_forum_user_board_show", array("boardId" => $this->getAttribute((isset($context["sidebar_board"]) ? $context["sidebar_board"] : null), "id"), "forumName" => (isset($context["forumName"]) ? $context["forumName"] : null))), "html", null, true);
                                echo "\"
\t\t\t\t\t\t\t\t\t\t\t\t title=\"";
                                // line 44
                                echo twig_escape_filter($this->env, $this->getAttribute((isset($context["sidebar_board"]) ? $context["sidebar_board"] : null), "name"), "html", null, true);
                                echo "\">
\t\t\t\t\t\t\t\t\t\t\t\t\t<i class=\"glyphicon glyphicon-folder-close\"></i>";
                            }
                        } else {
                            // line 48
                            echo "<li>
\t\t\t\t\t\t\t\t\t\t\t\t<a href=\"";
                            // line 49
                            echo twig_escape_filter($this->env, $this->env->getExtension('routing')->getPath("ccdn_forum_user_board_show", array("boardId" => $this->getAttribute((isset($context["sidebar_board"]) ? $context["sidebar_board"] : null), "id"), "forumName" => (isset($context["forumName"]) ? $context["forumName"] : null))), "html", null, true);
                            echo "\"
\t\t\t\t\t\t\t\t\t\t\t\t title=\"";
                            // line 50
                            echo twig_escape_filter($this->env, $this->getAttribute((isset($context["sidebar_board"]) ? $context["sidebar_board"] : null), "name"), "html", null, true);
                            echo "\">
\t\t\t\t\t\t\t\t\t\t\t\t\t<i class=\"glyphicon glyphicon-folder-close\"></i>";
                        }
                        // line 53
                        echo twig_escape_filter($this->env, $this->getAttribute((isset($context["sidebar_board"]) ? $context["sidebar_board"] : null), "name"), "html", null, true);
                        // line 54
                        echo "</a>
\t\t\t\t\t\t\t\t\t\t\t</li>";
                    }
                    $_parent = $context['_parent'];
                    unset($context['_seq'], $context['_iterated'], $context['_key'], $context['sidebar_board'], $context['_parent'], $context['loop']);
                    $context = array_intersect_key($context, $_parent) + $_parent;
                    // line 57
                    echo "</ul>
\t\t\t\t\t\t</li>";
                }
            }
            $_parent = $context['_parent'];
            unset($context['_seq'], $context['_iterated'], $context['_key'], $context['sidebar_category'], $context['_parent'], $context['loop']);
            $context = array_intersect_key($context, $_parent) + $_parent;
            // line 61
            echo "</ul>
\t\t</li>";
        }
        echo trim(preg_replace('/>\s+</', '><', ob_get_clean()));
    }

    public function getTemplateName()
    {
        return "CCDNForumForumBundle:Common/Layout/Sidebar/Partial:user_boards.html.twig";
    }

    public function isTraitable()
    {
        return false;
    }

    public function getDebugInfo()
    {
        return array (  205 => 79,  234 => 94,  297 => 118,  956 => 271,  953 => 270,  946 => 302,  942 => 300,  933 => 296,  925 => 292,  917 => 291,  914 => 290,  912 => 289,  909 => 288,  901 => 285,  898 => 284,  890 => 281,  887 => 280,  879 => 277,  870 => 274,  868 => 273,  863 => 269,  853 => 261,  848 => 258,  840 => 253,  834 => 249,  832 => 248,  822 => 244,  820 => 243,  816 => 241,  810 => 238,  807 => 237,  805 => 236,  802 => 235,  799 => 234,  791 => 262,  788 => 233,  773 => 264,  771 => 232,  768 => 231,  765 => 230,  757 => 221,  743 => 217,  738 => 214,  732 => 213,  720 => 211,  713 => 209,  688 => 202,  682 => 201,  679 => 200,  673 => 198,  668 => 197,  665 => 196,  663 => 195,  660 => 194,  657 => 193,  647 => 191,  632 => 187,  629 => 186,  626 => 184,  610 => 181,  603 => 179,  600 => 178,  588 => 175,  570 => 164,  561 => 161,  554 => 224,  522 => 156,  479 => 135,  471 => 129,  451 => 120,  418 => 112,  373 => 102,  370 => 101,  356 => 126,  624 => 224,  620 => 223,  612 => 220,  601 => 216,  594 => 176,  585 => 209,  580 => 207,  574 => 205,  572 => 204,  566 => 203,  559 => 201,  551 => 221,  545 => 198,  526 => 190,  507 => 156,  497 => 156,  485 => 124,  463 => 117,  447 => 113,  424 => 114,  412 => 126,  410 => 110,  406 => 111,  404 => 90,  401 => 89,  391 => 163,  376 => 103,  369 => 148,  359 => 144,  333 => 132,  329 => 130,  326 => 86,  318 => 86,  261 => 104,  195 => 84,  306 => 95,  303 => 123,  292 => 119,  287 => 77,  280 => 87,  178 => 73,  12 => 36,  118 => 49,  778 => 267,  763 => 244,  760 => 222,  748 => 242,  745 => 241,  742 => 240,  736 => 238,  734 => 237,  717 => 210,  714 => 232,  711 => 231,  703 => 226,  700 => 205,  653 => 218,  650 => 192,  644 => 190,  633 => 209,  616 => 182,  599 => 215,  595 => 205,  587 => 203,  584 => 173,  581 => 201,  578 => 200,  573 => 198,  546 => 175,  534 => 162,  531 => 225,  521 => 182,  513 => 230,  499 => 173,  475 => 169,  473 => 168,  468 => 128,  454 => 121,  448 => 119,  445 => 152,  429 => 148,  422 => 147,  399 => 139,  396 => 138,  348 => 118,  345 => 116,  340 => 91,  330 => 103,  307 => 123,  300 => 122,  291 => 115,  286 => 115,  190 => 72,  321 => 128,  295 => 100,  274 => 111,  242 => 82,  236 => 92,  70 => 25,  1414 => 421,  1408 => 419,  1402 => 417,  1400 => 416,  1398 => 415,  1394 => 414,  1385 => 413,  1383 => 412,  1380 => 411,  1367 => 405,  1361 => 403,  1355 => 401,  1353 => 400,  1351 => 399,  1347 => 398,  1341 => 397,  1339 => 396,  1336 => 395,  1323 => 389,  1317 => 387,  1311 => 385,  1309 => 384,  1307 => 383,  1303 => 382,  1297 => 381,  1291 => 380,  1287 => 379,  1283 => 378,  1279 => 377,  1273 => 376,  1271 => 375,  1268 => 374,  1256 => 369,  1251 => 368,  1249 => 367,  1246 => 366,  1237 => 360,  1231 => 358,  1228 => 357,  1223 => 356,  1221 => 355,  1218 => 354,  1211 => 349,  1202 => 347,  1198 => 346,  1195 => 345,  1192 => 344,  1190 => 343,  1187 => 342,  1179 => 338,  1177 => 337,  1174 => 336,  1168 => 332,  1162 => 330,  1159 => 329,  1157 => 328,  1154 => 327,  1145 => 322,  1143 => 321,  1118 => 320,  1115 => 319,  1112 => 318,  1109 => 317,  1106 => 316,  1103 => 315,  1100 => 314,  1098 => 313,  1095 => 312,  1088 => 308,  1084 => 307,  1079 => 306,  1077 => 305,  1074 => 304,  1067 => 299,  1064 => 298,  1056 => 293,  1053 => 292,  1051 => 291,  1048 => 290,  1040 => 285,  1036 => 284,  1032 => 283,  1029 => 282,  1027 => 281,  1024 => 280,  1016 => 276,  1014 => 272,  1012 => 271,  1009 => 270,  1004 => 266,  982 => 261,  979 => 260,  976 => 259,  973 => 258,  970 => 257,  967 => 256,  964 => 255,  961 => 254,  958 => 253,  955 => 252,  952 => 251,  950 => 269,  947 => 249,  939 => 243,  936 => 297,  934 => 241,  931 => 295,  923 => 236,  920 => 235,  918 => 234,  915 => 233,  903 => 286,  900 => 228,  897 => 227,  894 => 226,  892 => 282,  889 => 224,  881 => 278,  878 => 219,  876 => 276,  873 => 217,  865 => 272,  862 => 212,  860 => 268,  857 => 267,  849 => 206,  846 => 205,  844 => 204,  841 => 203,  833 => 199,  830 => 198,  828 => 246,  825 => 196,  817 => 192,  814 => 191,  812 => 190,  809 => 189,  801 => 185,  798 => 184,  796 => 233,  793 => 182,  785 => 232,  783 => 177,  780 => 303,  772 => 248,  769 => 247,  767 => 246,  764 => 169,  756 => 165,  753 => 220,  751 => 163,  749 => 218,  746 => 161,  739 => 239,  729 => 235,  724 => 154,  721 => 153,  715 => 151,  712 => 150,  710 => 149,  707 => 208,  699 => 142,  697 => 141,  696 => 204,  695 => 139,  694 => 138,  689 => 137,  680 => 134,  675 => 132,  662 => 125,  658 => 124,  654 => 123,  649 => 122,  643 => 120,  640 => 211,  638 => 210,  619 => 183,  617 => 112,  614 => 111,  598 => 107,  596 => 106,  593 => 105,  576 => 199,  564 => 162,  557 => 96,  550 => 187,  547 => 93,  527 => 91,  515 => 305,  512 => 84,  509 => 228,  503 => 81,  496 => 172,  493 => 143,  478 => 74,  467 => 72,  456 => 68,  450 => 114,  428 => 116,  414 => 144,  408 => 109,  390 => 136,  388 => 42,  377 => 129,  371 => 35,  363 => 32,  350 => 26,  342 => 23,  335 => 133,  332 => 88,  316 => 132,  313 => 84,  290 => 90,  276 => 110,  266 => 106,  263 => 105,  255 => 353,  245 => 83,  207 => 80,  194 => 52,  76 => 19,  200 => 75,  184 => 75,  157 => 64,  83 => 34,  58 => 20,  170 => 64,  139 => 56,  563 => 202,  560 => 191,  558 => 160,  553 => 188,  549 => 182,  543 => 174,  537 => 159,  532 => 192,  528 => 160,  525 => 157,  523 => 189,  518 => 180,  514 => 167,  511 => 166,  508 => 165,  501 => 154,  491 => 157,  487 => 156,  460 => 123,  455 => 115,  449 => 138,  442 => 151,  439 => 150,  436 => 132,  433 => 149,  426 => 58,  420 => 146,  415 => 127,  411 => 143,  405 => 108,  403 => 48,  380 => 130,  366 => 150,  354 => 101,  331 => 135,  325 => 94,  308 => 126,  304 => 122,  272 => 108,  267 => 105,  249 => 74,  216 => 86,  155 => 63,  146 => 10,  126 => 47,  124 => 46,  188 => 70,  181 => 81,  161 => 27,  320 => 84,  317 => 127,  311 => 128,  288 => 114,  284 => 114,  279 => 77,  275 => 86,  256 => 103,  250 => 99,  237 => 71,  232 => 91,  222 => 85,  191 => 26,  153 => 62,  150 => 34,  145 => 61,  110 => 44,  692 => 399,  683 => 223,  678 => 133,  676 => 199,  666 => 222,  661 => 220,  656 => 219,  652 => 376,  645 => 369,  641 => 189,  635 => 188,  631 => 364,  625 => 361,  615 => 354,  607 => 180,  597 => 177,  590 => 204,  583 => 334,  579 => 332,  577 => 206,  575 => 328,  569 => 325,  565 => 324,  555 => 200,  548 => 176,  540 => 160,  536 => 194,  529 => 159,  524 => 90,  516 => 294,  510 => 178,  504 => 155,  500 => 291,  495 => 158,  490 => 142,  486 => 286,  482 => 136,  470 => 121,  464 => 125,  459 => 116,  452 => 268,  434 => 118,  421 => 90,  417 => 145,  400 => 47,  385 => 159,  361 => 124,  344 => 24,  339 => 191,  324 => 110,  310 => 83,  302 => 79,  296 => 121,  282 => 161,  259 => 103,  244 => 96,  231 => 69,  226 => 131,  215 => 280,  186 => 69,  152 => 74,  114 => 44,  104 => 40,  96 => 44,  358 => 123,  351 => 141,  347 => 140,  343 => 92,  338 => 113,  327 => 131,  323 => 85,  319 => 124,  315 => 98,  301 => 80,  299 => 8,  293 => 90,  289 => 117,  281 => 113,  277 => 112,  271 => 110,  265 => 106,  262 => 81,  260 => 363,  257 => 103,  251 => 101,  248 => 116,  239 => 93,  228 => 89,  225 => 87,  213 => 82,  211 => 81,  197 => 74,  174 => 65,  148 => 69,  134 => 50,  127 => 49,  270 => 84,  253 => 78,  233 => 304,  212 => 60,  210 => 81,  206 => 57,  202 => 76,  198 => 80,  192 => 73,  185 => 61,  180 => 44,  175 => 41,  172 => 70,  167 => 76,  165 => 75,  160 => 66,  137 => 57,  120 => 57,  113 => 43,  100 => 22,  90 => 56,  81 => 31,  65 => 22,  129 => 53,  97 => 39,  84 => 20,  34 => 10,  53 => 18,  37 => 17,  52 => 31,  77 => 29,  74 => 48,  20 => 11,  23 => 5,  480 => 75,  474 => 122,  469 => 158,  461 => 70,  457 => 153,  453 => 151,  444 => 263,  440 => 148,  437 => 61,  435 => 146,  430 => 255,  427 => 143,  423 => 57,  413 => 241,  409 => 132,  407 => 238,  402 => 107,  398 => 88,  393 => 168,  387 => 110,  384 => 106,  381 => 105,  379 => 104,  374 => 128,  368 => 126,  365 => 141,  362 => 148,  360 => 128,  355 => 122,  341 => 131,  337 => 90,  322 => 93,  314 => 88,  312 => 125,  309 => 82,  305 => 124,  298 => 101,  294 => 90,  285 => 78,  283 => 97,  278 => 111,  268 => 373,  264 => 105,  258 => 72,  252 => 102,  247 => 98,  241 => 94,  229 => 73,  220 => 84,  214 => 63,  177 => 41,  169 => 33,  140 => 66,  132 => 65,  128 => 53,  111 => 42,  107 => 52,  61 => 43,  273 => 85,  269 => 109,  254 => 102,  246 => 67,  243 => 97,  240 => 72,  238 => 95,  235 => 63,  230 => 93,  227 => 92,  224 => 39,  221 => 88,  219 => 87,  217 => 83,  208 => 124,  204 => 82,  179 => 67,  159 => 196,  143 => 54,  135 => 113,  131 => 54,  119 => 49,  108 => 85,  102 => 34,  71 => 24,  67 => 20,  63 => 23,  59 => 41,  47 => 15,  38 => 12,  94 => 38,  89 => 36,  85 => 53,  79 => 33,  75 => 28,  68 => 39,  56 => 19,  50 => 17,  29 => 13,  87 => 35,  72 => 43,  55 => 32,  21 => 3,  26 => 1,  98 => 39,  93 => 43,  88 => 36,  78 => 32,  46 => 12,  27 => 8,  40 => 18,  44 => 12,  35 => 6,  31 => 4,  43 => 8,  41 => 13,  28 => 8,  201 => 56,  196 => 52,  183 => 68,  171 => 81,  166 => 30,  163 => 28,  158 => 74,  156 => 76,  151 => 20,  142 => 30,  138 => 51,  136 => 70,  123 => 50,  121 => 46,  117 => 46,  115 => 44,  105 => 30,  101 => 37,  91 => 37,  69 => 21,  66 => 24,  62 => 21,  49 => 17,  24 => 18,  32 => 9,  25 => 6,  22 => 2,  19 => 1,  209 => 58,  203 => 86,  199 => 85,  193 => 51,  189 => 52,  187 => 85,  182 => 47,  176 => 72,  173 => 46,  168 => 80,  164 => 61,  162 => 74,  154 => 21,  149 => 61,  147 => 60,  144 => 26,  141 => 7,  133 => 30,  130 => 54,  125 => 48,  122 => 47,  116 => 48,  112 => 43,  109 => 41,  106 => 43,  103 => 42,  99 => 39,  95 => 38,  92 => 37,  86 => 27,  82 => 52,  80 => 43,  73 => 29,  64 => 22,  60 => 35,  57 => 19,  54 => 37,  51 => 16,  48 => 7,  45 => 14,  42 => 8,  39 => 9,  36 => 11,  33 => 22,  30 => 5,);
    }
}
