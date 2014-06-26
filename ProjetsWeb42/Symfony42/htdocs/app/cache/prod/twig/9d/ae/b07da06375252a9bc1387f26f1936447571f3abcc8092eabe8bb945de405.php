<?php

/* CCDNForumForumBundle:User/Board:show.html.twig */
class __TwigTemplate_9daeb07da06375252a9bc1387f26f1936447571f3abcc8092eabe8bb945de405 extends Twig_Template
{
    public function __construct(Twig_Environment $env)
    {
        parent::__construct($env);

        $this->parent = $this->env->loadTemplate("CCDNForumForumBundle:Common:Layout/base.html.twig");

        $this->blocks = array(
            'title' => array($this, 'block_title'),
            'sidebar' => array($this, 'block_sidebar'),
            'body_content' => array($this, 'block_body_content'),
        );
    }

    protected function doGetParent(array $context)
    {
        return "CCDNForumForumBundle:Common:Layout/base.html.twig";
    }

    protected function doDisplay(array $context, array $blocks = array())
    {
        // line 3
        $context["LayoutTemplate"] = $this->getAttribute($this->getAttribute($this->getAttribute($this->getAttribute((isset($context["ccdn_forum_forum"]) ? $context["ccdn_forum_forum"] : null), "board"), "user"), "show"), "layout_template");
        $this->parent->display($context, array_merge($this->blocks, $blocks));
    }

    // line 5
    public function block_title($context, array $blocks = array())
    {
        // line 6
        echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("title.board.show", array("%board_name%" => $this->getAttribute((isset($context["board"]) ? $context["board"] : null), "name")), "CCDNForumForumBundle"), "html", null, true);
    }

    // line 9
    public function block_sidebar($context, array $blocks = array())
    {
        // line 10
        ob_start();
        // line 11
        $this->displayParentBlock("sidebar", $context, $blocks);
        // line 12
        $this->env->loadTemplate("CCDNForumForumBundle:Common:Layout/Sidebar/user_forum.html.twig")->display($context);
        echo trim(preg_replace('/>\s+</', '><', ob_get_clean()));
    }

    // line 16
    public function block_body_content($context, array $blocks = array())
    {
        // line 17
        ob_start();
        // line 19
        echo "<section class=\"row btn-toolbar clearfix\">
            ";
        // line 20
        $context["is_topic_create_disabled"] = (($this->getAttribute((isset($context["board"]) ? $context["board"] : null), "isAuthorisedToCreateTopic", array(0 => $this->getAttribute((isset($context["app"]) ? $context["app"] : null), "security")), "method")) ? ("") : (" disabled"));
        // line 21
        echo "
            <a class=\"btn btn-danger";
        // line 22
        echo twig_escape_filter($this->env, (isset($context["is_topic_create_disabled"]) ? $context["is_topic_create_disabled"] : null), "html", null, true);
        echo "\" rel=\"nofollow\" href=\"";
        echo twig_escape_filter($this->env, $this->env->getExtension('routing')->getPath("ccdn_forum_user_topic_create", array("forumName" => (isset($context["forumName"]) ? $context["forumName"] : null), "boardId" => $this->getAttribute((isset($context["board"]) ? $context["board"] : null), "getId"))), "html", null, true);
        echo "\">
\t\t\t\t<i class=\"glyphicon glyphicon-asterisk\"></i>";
        // line 24
        echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("link.topic.create", array(), "CCDNForumForumBundle"), "html", null, true);
        // line 25
        echo "</a>

\t</section>

\t<header class=\"row clearfix\">
\t\t<div class=\"col-md-6\">
\t\t    <span class=\"lead\" title=\"";
        // line 31
        echo twig_escape_filter($this->env, $this->getAttribute((isset($context["board"]) ? $context["board"] : null), "name"), "html", null, true);
        echo "\">";
        echo twig_escape_filter($this->env, $this->getAttribute((isset($context["board"]) ? $context["board"] : null), "name"), "html", null, true);
        echo "</span>
\t\t</div>
\t\t<div class=\"col-md-6 text-right\">
\t\t    <span class=\"label label-default\" title=\"";
        // line 34
        echo twig_escape_filter($this->env, $this->getAttribute((isset($context["board"]) ? $context["board"] : null), "cachedTopicCount"), "html", null, true);
        echo "\">";
        // line 35
        echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("board.topic-count-label", array(), "CCDNForumForumBundle"), "html", null, true);
        // line 36
        echo twig_escape_filter($this->env, $this->getAttribute((isset($context["board"]) ? $context["board"] : null), "cachedTopicCount"), "html", null, true);
        // line 37
        echo "</span>
\t\t\t&nbsp;
\t\t    <span class=\"label label-default\" title=\"";
        // line 39
        echo twig_escape_filter($this->env, $this->getAttribute((isset($context["board"]) ? $context["board"] : null), "cachedPostCount"), "html", null, true);
        echo "\">";
        // line 40
        echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("board.post-count-label", array(), "CCDNForumForumBundle"), "html", null, true);
        // line 41
        echo twig_escape_filter($this->env, $this->getAttribute((isset($context["board"]) ? $context["board"] : null), "cachedPostCount"), "html", null, true);
        // line 42
        echo "</span>
\t\t</div>
\t</header>";
        // line 46
        echo $this->env->getExtension('knp_pagination')->render((isset($context["pager"]) ? $context["pager"] : null));
        // line 48
        echo "<section class=\"clearfix\">
        <table class=\"table table-striped table-hover\">
            <thead>
                <tr>
                    <th class=\"center\" style=\"width: 18px;\"></th>
                    <th class=\"center\" style=\"width: 18px;\"></th>
                    <th class=\"left\">";
        // line 54
        echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("board.topic-th", array(), "CCDNForumForumBundle"), "html", null, true);
        echo "</th>
                    <th class=\"center\" style=\"width: 80px;\">";
        // line 55
        echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("board.reply-count-th", array(), "CCDNForumForumBundle"), "html", null, true);
        echo "</th>
                    <th class=\"center\" style=\"width: 80px;\">";
        // line 56
        echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("board.view-count-th", array(), "CCDNForumForumBundle"), "html", null, true);
        echo "</th>
                    <th class=\"center\" style=\"width: 170px;\">";
        // line 57
        echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("board.last-post-th", array(), "CCDNForumForumBundle"), "html", null, true);
        echo "</th>
                </tr>
            </thead>
            <tbody>";
        // line 61
        if ((!twig_test_empty((isset($context["sticky_topics"]) ? $context["sticky_topics"] : null)))) {
            // line 62
            echo "<tr>
\t\t\t\t\t\t<td colspan=\"6\" class=\"row-group-heading\">";
            // line 64
            echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("board.announcements-th", array(), "CCDNForumForumBundle"), "html", null, true);
            // line 65
            echo "</td>
\t\t\t\t\t</tr>";
            // line 68
            $context['_parent'] = (array) $context;
            $context['_seq'] = twig_ensure_traversable((isset($context["sticky_topics"]) ? $context["sticky_topics"] : null));
            $context['loop'] = array(
              'parent' => $context['_parent'],
              'index0' => 0,
              'index'  => 1,
              'first'  => true,
            );
            if (is_array($context['_seq']) || (is_object($context['_seq']) && $context['_seq'] instanceof Countable)) {
                $length = count($context['_seq']);
                $context['loop']['revindex0'] = $length - 1;
                $context['loop']['revindex'] = $length;
                $context['loop']['length'] = $length;
                $context['loop']['last'] = 1 === $length;
            }
            foreach ($context['_seq'] as $context["row"] => $context["topic"]) {
                // line 69
                if (((!$this->getAttribute((isset($context["topic"]) ? $context["topic"] : null), "isDeleted")) || $this->env->getExtension('security')->isGranted("ROLE_MODERATOR"))) {
                    // line 70
                    $this->env->loadTemplate("CCDNForumForumBundle:User:Board/Partial/item_topic_list.html.twig")->display($context);
                }
                ++$context['loop']['index0'];
                ++$context['loop']['index'];
                $context['loop']['first'] = false;
                if (isset($context['loop']['length'])) {
                    --$context['loop']['revindex0'];
                    --$context['loop']['revindex'];
                    $context['loop']['last'] = 0 === $context['loop']['revindex0'];
                }
            }
            $_parent = $context['_parent'];
            unset($context['_seq'], $context['_iterated'], $context['row'], $context['topic'], $context['_parent'], $context['loop']);
            $context = array_intersect_key($context, $_parent) + $_parent;
            // line 74
            echo "<tr>
\t\t\t\t\t\t<td colspan=\"6\" class=\"row-group-heading\">";
            // line 76
            echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("board.topics-th", array(), "CCDNForumForumBundle"), "html", null, true);
            // line 77
            echo "</td>
\t\t\t\t\t</tr>";
        }
        // line 81
        $context['_parent'] = (array) $context;
        $context['_seq'] = twig_ensure_traversable($this->getAttribute((isset($context["pager"]) ? $context["pager"] : null), "getItems", array(), "method"));
        $context['_iterated'] = false;
        $context['loop'] = array(
          'parent' => $context['_parent'],
          'index0' => 0,
          'index'  => 1,
          'first'  => true,
        );
        if (is_array($context['_seq']) || (is_object($context['_seq']) && $context['_seq'] instanceof Countable)) {
            $length = count($context['_seq']);
            $context['loop']['revindex0'] = $length - 1;
            $context['loop']['revindex'] = $length;
            $context['loop']['length'] = $length;
            $context['loop']['last'] = 1 === $length;
        }
        foreach ($context['_seq'] as $context["row"] => $context["topic"]) {
            // line 82
            if (((!$this->getAttribute((isset($context["topic"]) ? $context["topic"] : null), "isDeleted")) || $this->env->getExtension('security')->isGranted("ROLE_MODERATOR"))) {
                // line 83
                $this->env->loadTemplate("CCDNForumForumBundle:User:Board/Partial/item_topic_list.html.twig")->display($context);
            }
            $context['_iterated'] = true;
            ++$context['loop']['index0'];
            ++$context['loop']['index'];
            $context['loop']['first'] = false;
            if (isset($context['loop']['length'])) {
                --$context['loop']['revindex0'];
                --$context['loop']['revindex'];
                $context['loop']['last'] = 0 === $context['loop']['revindex0'];
            }
        }
        if (!$context['_iterated']) {
            // line 86
            echo "<tr>
\t\t                <td class=\"center\" colspan=\"6\">";
            // line 88
            echo twig_escape_filter($this->env, $this->env->getExtension('translator')->trans("board.no-topics", array(), "CCDNForumForumBundle"), "html", null, true);
            // line 89
            echo "</td>
\t\t            </tr>";
        }
        $_parent = $context['_parent'];
        unset($context['_seq'], $context['_iterated'], $context['row'], $context['topic'], $context['_parent'], $context['loop']);
        $context = array_intersect_key($context, $_parent) + $_parent;
        // line 92
        echo "</tbody>
        </table>
\t</section>";
        // line 96
        echo $this->env->getExtension('knp_pagination')->render((isset($context["pager"]) ? $context["pager"] : null));
        echo trim(preg_replace('/>\s+</', '><', ob_get_clean()));
    }

    public function getTemplateName()
    {
        return "CCDNForumForumBundle:User/Board:show.html.twig";
    }

    public function isTraitable()
    {
        return false;
    }

    public function getDebugInfo()
    {
        return array (  205 => 79,  234 => 94,  297 => 118,  956 => 271,  953 => 270,  946 => 302,  942 => 300,  933 => 296,  925 => 292,  917 => 291,  914 => 290,  912 => 289,  909 => 288,  901 => 285,  898 => 284,  890 => 281,  887 => 280,  879 => 277,  870 => 274,  868 => 273,  863 => 269,  853 => 261,  848 => 258,  840 => 253,  834 => 249,  832 => 248,  822 => 244,  820 => 243,  816 => 241,  810 => 238,  807 => 237,  805 => 236,  802 => 235,  799 => 234,  791 => 262,  788 => 233,  773 => 264,  771 => 232,  768 => 231,  765 => 230,  757 => 221,  743 => 217,  738 => 214,  732 => 213,  720 => 211,  713 => 209,  688 => 202,  682 => 201,  679 => 200,  673 => 198,  668 => 197,  665 => 196,  663 => 195,  660 => 194,  657 => 193,  647 => 191,  632 => 187,  629 => 186,  626 => 184,  610 => 181,  603 => 179,  600 => 178,  588 => 175,  570 => 164,  561 => 161,  554 => 224,  522 => 156,  479 => 135,  471 => 129,  451 => 120,  418 => 112,  373 => 102,  370 => 101,  356 => 126,  624 => 224,  620 => 223,  612 => 220,  601 => 216,  594 => 176,  585 => 209,  580 => 207,  574 => 205,  572 => 204,  566 => 203,  559 => 201,  551 => 221,  545 => 198,  526 => 190,  507 => 156,  497 => 156,  485 => 124,  463 => 117,  447 => 113,  424 => 114,  412 => 126,  410 => 110,  406 => 111,  404 => 90,  401 => 89,  391 => 163,  376 => 103,  369 => 148,  359 => 144,  333 => 132,  329 => 130,  326 => 86,  318 => 86,  261 => 104,  195 => 84,  306 => 95,  303 => 123,  292 => 119,  287 => 77,  280 => 87,  178 => 73,  12 => 36,  118 => 49,  778 => 267,  763 => 244,  760 => 222,  748 => 242,  745 => 241,  742 => 240,  736 => 238,  734 => 237,  717 => 210,  714 => 232,  711 => 231,  703 => 226,  700 => 205,  653 => 218,  650 => 192,  644 => 190,  633 => 209,  616 => 182,  599 => 215,  595 => 205,  587 => 203,  584 => 173,  581 => 201,  578 => 200,  573 => 198,  546 => 175,  534 => 162,  531 => 225,  521 => 182,  513 => 230,  499 => 173,  475 => 169,  473 => 168,  468 => 128,  454 => 121,  448 => 119,  445 => 152,  429 => 148,  422 => 147,  399 => 139,  396 => 138,  348 => 118,  345 => 116,  340 => 91,  330 => 103,  307 => 123,  300 => 122,  291 => 115,  286 => 115,  190 => 72,  321 => 128,  295 => 100,  274 => 111,  242 => 82,  236 => 92,  70 => 24,  1414 => 421,  1408 => 419,  1402 => 417,  1400 => 416,  1398 => 415,  1394 => 414,  1385 => 413,  1383 => 412,  1380 => 411,  1367 => 405,  1361 => 403,  1355 => 401,  1353 => 400,  1351 => 399,  1347 => 398,  1341 => 397,  1339 => 396,  1336 => 395,  1323 => 389,  1317 => 387,  1311 => 385,  1309 => 384,  1307 => 383,  1303 => 382,  1297 => 381,  1291 => 380,  1287 => 379,  1283 => 378,  1279 => 377,  1273 => 376,  1271 => 375,  1268 => 374,  1256 => 369,  1251 => 368,  1249 => 367,  1246 => 366,  1237 => 360,  1231 => 358,  1228 => 357,  1223 => 356,  1221 => 355,  1218 => 354,  1211 => 349,  1202 => 347,  1198 => 346,  1195 => 345,  1192 => 344,  1190 => 343,  1187 => 342,  1179 => 338,  1177 => 337,  1174 => 336,  1168 => 332,  1162 => 330,  1159 => 329,  1157 => 328,  1154 => 327,  1145 => 322,  1143 => 321,  1118 => 320,  1115 => 319,  1112 => 318,  1109 => 317,  1106 => 316,  1103 => 315,  1100 => 314,  1098 => 313,  1095 => 312,  1088 => 308,  1084 => 307,  1079 => 306,  1077 => 305,  1074 => 304,  1067 => 299,  1064 => 298,  1056 => 293,  1053 => 292,  1051 => 291,  1048 => 290,  1040 => 285,  1036 => 284,  1032 => 283,  1029 => 282,  1027 => 281,  1024 => 280,  1016 => 276,  1014 => 272,  1012 => 271,  1009 => 270,  1004 => 266,  982 => 261,  979 => 260,  976 => 259,  973 => 258,  970 => 257,  967 => 256,  964 => 255,  961 => 254,  958 => 253,  955 => 252,  952 => 251,  950 => 269,  947 => 249,  939 => 243,  936 => 297,  934 => 241,  931 => 295,  923 => 236,  920 => 235,  918 => 234,  915 => 233,  903 => 286,  900 => 228,  897 => 227,  894 => 226,  892 => 282,  889 => 224,  881 => 278,  878 => 219,  876 => 276,  873 => 217,  865 => 272,  862 => 212,  860 => 268,  857 => 267,  849 => 206,  846 => 205,  844 => 204,  841 => 203,  833 => 199,  830 => 198,  828 => 246,  825 => 196,  817 => 192,  814 => 191,  812 => 190,  809 => 189,  801 => 185,  798 => 184,  796 => 233,  793 => 182,  785 => 232,  783 => 177,  780 => 303,  772 => 248,  769 => 247,  767 => 246,  764 => 169,  756 => 165,  753 => 220,  751 => 163,  749 => 218,  746 => 161,  739 => 239,  729 => 235,  724 => 154,  721 => 153,  715 => 151,  712 => 150,  710 => 149,  707 => 208,  699 => 142,  697 => 141,  696 => 204,  695 => 139,  694 => 138,  689 => 137,  680 => 134,  675 => 132,  662 => 125,  658 => 124,  654 => 123,  649 => 122,  643 => 120,  640 => 211,  638 => 210,  619 => 183,  617 => 112,  614 => 111,  598 => 107,  596 => 106,  593 => 105,  576 => 199,  564 => 162,  557 => 96,  550 => 187,  547 => 93,  527 => 91,  515 => 305,  512 => 84,  509 => 228,  503 => 81,  496 => 172,  493 => 143,  478 => 74,  467 => 72,  456 => 68,  450 => 114,  428 => 116,  414 => 144,  408 => 109,  390 => 136,  388 => 42,  377 => 129,  371 => 35,  363 => 32,  350 => 26,  342 => 23,  335 => 133,  332 => 88,  316 => 132,  313 => 84,  290 => 90,  276 => 110,  266 => 106,  263 => 105,  255 => 353,  245 => 83,  207 => 80,  194 => 52,  76 => 34,  200 => 75,  184 => 75,  157 => 81,  83 => 37,  58 => 20,  170 => 85,  139 => 56,  563 => 202,  560 => 191,  558 => 160,  553 => 188,  549 => 182,  543 => 174,  537 => 159,  532 => 192,  528 => 160,  525 => 157,  523 => 189,  518 => 180,  514 => 167,  511 => 166,  508 => 165,  501 => 154,  491 => 157,  487 => 156,  460 => 123,  455 => 115,  449 => 138,  442 => 151,  439 => 150,  436 => 132,  433 => 149,  426 => 58,  420 => 146,  415 => 127,  411 => 143,  405 => 108,  403 => 48,  380 => 130,  366 => 150,  354 => 101,  331 => 135,  325 => 94,  308 => 126,  304 => 122,  272 => 108,  267 => 105,  249 => 74,  216 => 86,  155 => 63,  146 => 10,  126 => 47,  124 => 55,  188 => 70,  181 => 81,  161 => 27,  320 => 84,  317 => 127,  311 => 128,  288 => 114,  284 => 114,  279 => 77,  275 => 86,  256 => 103,  250 => 99,  237 => 92,  232 => 91,  222 => 85,  191 => 81,  153 => 78,  150 => 34,  145 => 65,  110 => 46,  692 => 399,  683 => 223,  678 => 133,  676 => 199,  666 => 222,  661 => 220,  656 => 219,  652 => 376,  645 => 369,  641 => 189,  635 => 188,  631 => 364,  625 => 361,  615 => 354,  607 => 180,  597 => 177,  590 => 204,  583 => 334,  579 => 332,  577 => 206,  575 => 328,  569 => 325,  565 => 324,  555 => 200,  548 => 176,  540 => 160,  536 => 194,  529 => 159,  524 => 90,  516 => 294,  510 => 178,  504 => 155,  500 => 291,  495 => 158,  490 => 142,  486 => 286,  482 => 136,  470 => 121,  464 => 125,  459 => 116,  452 => 268,  434 => 118,  421 => 90,  417 => 145,  400 => 47,  385 => 159,  361 => 124,  344 => 24,  339 => 191,  324 => 110,  310 => 83,  302 => 79,  296 => 121,  282 => 161,  259 => 103,  244 => 96,  231 => 69,  226 => 131,  215 => 280,  186 => 69,  152 => 74,  114 => 44,  104 => 41,  96 => 45,  358 => 123,  351 => 141,  347 => 140,  343 => 92,  338 => 113,  327 => 131,  323 => 85,  319 => 124,  315 => 98,  301 => 80,  299 => 8,  293 => 90,  289 => 117,  281 => 113,  277 => 112,  271 => 110,  265 => 106,  262 => 81,  260 => 363,  257 => 103,  251 => 101,  248 => 116,  239 => 93,  228 => 88,  225 => 86,  213 => 82,  211 => 83,  197 => 74,  174 => 65,  148 => 68,  134 => 50,  127 => 62,  270 => 84,  253 => 78,  233 => 304,  212 => 60,  210 => 81,  206 => 57,  202 => 76,  198 => 80,  192 => 73,  185 => 76,  180 => 44,  175 => 89,  172 => 70,  167 => 70,  165 => 69,  160 => 66,  137 => 57,  120 => 54,  113 => 56,  100 => 22,  90 => 41,  81 => 35,  65 => 22,  129 => 63,  97 => 39,  84 => 40,  34 => 11,  53 => 18,  37 => 15,  52 => 27,  77 => 37,  74 => 33,  20 => 11,  23 => 5,  480 => 75,  474 => 122,  469 => 158,  461 => 70,  457 => 153,  453 => 151,  444 => 263,  440 => 148,  437 => 61,  435 => 146,  430 => 255,  427 => 143,  423 => 57,  413 => 241,  409 => 132,  407 => 238,  402 => 107,  398 => 88,  393 => 168,  387 => 110,  384 => 106,  381 => 105,  379 => 104,  374 => 128,  368 => 126,  365 => 141,  362 => 148,  360 => 128,  355 => 122,  341 => 131,  337 => 90,  322 => 93,  314 => 88,  312 => 125,  309 => 82,  305 => 124,  298 => 101,  294 => 90,  285 => 78,  283 => 97,  278 => 111,  268 => 373,  264 => 105,  258 => 72,  252 => 102,  247 => 98,  241 => 96,  229 => 73,  220 => 84,  214 => 63,  177 => 41,  169 => 33,  140 => 62,  132 => 57,  128 => 56,  111 => 53,  107 => 52,  61 => 21,  273 => 85,  269 => 109,  254 => 102,  246 => 67,  243 => 97,  240 => 72,  238 => 95,  235 => 63,  230 => 89,  227 => 92,  224 => 39,  221 => 88,  219 => 87,  217 => 83,  208 => 124,  204 => 82,  179 => 67,  159 => 196,  143 => 64,  135 => 113,  131 => 65,  119 => 57,  108 => 54,  102 => 40,  71 => 36,  67 => 20,  63 => 29,  59 => 20,  47 => 23,  38 => 15,  94 => 45,  89 => 43,  85 => 42,  79 => 33,  75 => 29,  68 => 32,  56 => 19,  50 => 26,  29 => 7,  87 => 40,  72 => 25,  55 => 32,  21 => 2,  26 => 5,  98 => 46,  93 => 36,  88 => 34,  78 => 32,  46 => 12,  27 => 3,  40 => 17,  44 => 11,  35 => 6,  31 => 8,  43 => 8,  41 => 16,  28 => 8,  201 => 56,  196 => 52,  183 => 68,  171 => 81,  166 => 30,  163 => 28,  158 => 74,  156 => 76,  151 => 77,  142 => 30,  138 => 61,  136 => 72,  123 => 50,  121 => 58,  117 => 46,  115 => 44,  105 => 30,  101 => 48,  91 => 35,  69 => 35,  66 => 38,  62 => 24,  49 => 20,  24 => 4,  32 => 5,  25 => 6,  22 => 2,  19 => 1,  209 => 82,  203 => 86,  199 => 85,  193 => 51,  189 => 52,  187 => 77,  182 => 74,  176 => 72,  173 => 46,  168 => 84,  164 => 61,  162 => 74,  154 => 21,  149 => 61,  147 => 60,  144 => 26,  141 => 7,  133 => 30,  130 => 54,  125 => 61,  122 => 47,  116 => 56,  112 => 48,  109 => 52,  106 => 42,  103 => 42,  99 => 39,  95 => 37,  92 => 42,  86 => 42,  82 => 39,  80 => 31,  73 => 28,  64 => 22,  60 => 21,  57 => 25,  54 => 17,  51 => 16,  48 => 7,  45 => 19,  42 => 10,  39 => 9,  36 => 12,  33 => 13,  30 => 5,);
    }
}
