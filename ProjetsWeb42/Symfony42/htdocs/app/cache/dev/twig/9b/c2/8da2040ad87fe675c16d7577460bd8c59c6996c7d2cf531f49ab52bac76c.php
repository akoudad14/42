<?php

/* WebProfilerBundle:Collector:exception.html.twig */
class __TwigTemplate_9bc28da2040ad87fe675c16d7577460bd8c59c6996c7d2cf531f49ab52bac76c extends Twig_Template
{
    public function __construct(Twig_Environment $env)
    {
        parent::__construct($env);

        $this->parent = $this->env->loadTemplate("@WebProfiler/Profiler/layout.html.twig");

        $this->blocks = array(
            'head' => array($this, 'block_head'),
            'menu' => array($this, 'block_menu'),
            'panel' => array($this, 'block_panel'),
        );
    }

    protected function doGetParent(array $context)
    {
        return "@WebProfiler/Profiler/layout.html.twig";
    }

    protected function doDisplay(array $context, array $blocks = array())
    {
        $this->parent->display($context, array_merge($this->blocks, $blocks));
    }

    // line 3
    public function block_head($context, array $blocks = array())
    {
        // line 4
        echo "    ";
        if ($this->getAttribute((isset($context["collector"]) ? $context["collector"] : $this->getContext($context, "collector")), "hasexception")) {
            // line 5
            echo "        <style>
            ";
            // line 6
            echo $this->env->getExtension('http_kernel')->renderFragment($this->env->getExtension('routing')->getPath("_profiler_exception_css", array("token" => (isset($context["token"]) ? $context["token"] : $this->getContext($context, "token")))));
            echo "
        </style>
    ";
        }
        // line 9
        echo "    ";
        $this->displayParentBlock("head", $context, $blocks);
        echo "
";
    }

    // line 12
    public function block_menu($context, array $blocks = array())
    {
        // line 13
        echo "<span class=\"label\">
    <span class=\"icon\"><img src=\"data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAACoAAAAeCAQAAADwIURrAAAEQ0lEQVR42sWVf0xbVRTHKSCUUNEsWdhE3BT3QzNMjHEydLz+eONnGS2sbBSkKBA7Nn6DGwb+EByLbMbFKEuUiG1kTrFgwmCODZaZqaGJEQYSMXQJMJFBs/pGlV9tv97bAukrZMD+8Z2k957vOfdzz7s579brwU+jSP2mojnmNgOXxQ4pLqa90SjyetjHEKQ6I7MwWGkyi+qMIWjDQPgUiuNMfBTf4kxlkfDZELJSynIMHmwsVyldNxaCC7soUjV/fcTawxmvjCscS6AUR9cdzsgZu0YVCwyiLV/uhGB9UFFmG4O0OXM7inEQCpTf6ZY7nEjbeCdKkUSs9O73iTYGmW0QrQfprWclBNHSAxWegD+ECEXmp0MU2nQLajxJFCH5VTfdYiBx6Fl4r6POYj0FcCcQAoFrG4T1fkS14VpscyEgwLaRU1Qr1rtqhY9mb7L6stCtuooIyd8JnSUvEkCoepiclg1y+C3HHx3NpoBZFQKWtQAoqaYeRijxfAvSxXYGWbXwX074oIwmFJ5FIMLlVjrvT4K/JlfKSTlNLkTf5VOtKwtCrUJ2VzKdXoaAH9VUk1sRTgiPlzdSr/IrbCbAvMi4SyWpprfoOd4sxyZEsDYarqrHM6wTz1qxu6CNzkq/xtMJY3QmWTDuLbtAZ1I7XkuR6V5pbCAqjNUIJlB1BwOx/T1DDpf678DxI5XDysUP8r4xO3bOOZu7USRbcOLnftCm3HOhrlWwJEoNh6TWmMn6VrLplDE/5/XsHV7aXxchNlorgys1Sz0Zb62YoGP5ZMzskhY9WzlKRy0XN7OkIdfwWeI/DJYs6abXUO3pybyZOnOCPd72xcAlPU4y2JjhMNKgky8ccMicZR360wv78Q4+4Vroidz+HEpkbhjKYmt3FUMG43iVtW5q7EPSLtiO8MES5wtbtKfa8/lLNHZPSIY9nue3Hs+oieHozHoeNTgJiaulfMFmTK9WRdW0+arEwde6rp+dWi035x4UCMNTEC02P14wn3/3PrsisWgUKrXOXVF2QH5sxDPvgOO0xXIOz/OuFzwGCWptHX2/XZtwT5ZbJ15i/Jj6ZaW+UNgRw9rcc7r/6htAG6oRhSCP6w4i7IAYh1HHryGz07AZAmYXk0VsCwSdW5N/52fgfaQSYBgCV70G4UvQiZ6vFjuWXq1JyguBT+GzGeWx455xJCJwjcsa4g23lJiu+/+h0R6I+IeCRiXM87rPzm+0fFssz0+YR9Ta0H3ZZl77W4/yNrk4XjDj7mebsW9taHjDDfdFP/W0DLp9ojOc7vLP7vGmq9izNnQLtB+PLZ6fo3kAxTihM7mO4Ijtj2YooW0edJ20BDoTchC8NtQPe/D2XHtvv+kXfIOjeI74RWgZ7OvtXWhAEoKxE8fwLfH70Uoiu/HIev6khdgOMZJxEBEIgR/8EYpXoYQCL2MTvOFH1EjiJ2M/ifivJPwHIs9MRJmsgVwAAAAASUVORK5CYII=\" alt=\"Exception\"></span>
    <strong>Exception</strong>
    <span class=\"count\">
        ";
        // line 17
        if ($this->getAttribute((isset($context["collector"]) ? $context["collector"] : $this->getContext($context, "collector")), "hasexception")) {
            // line 18
            echo "            <span>1</span>
        ";
        }
        // line 20
        echo "    </span>
</span>
";
    }

    // line 24
    public function block_panel($context, array $blocks = array())
    {
        // line 25
        echo "    <h2>Exception</h2>

    ";
        // line 27
        if ((!$this->getAttribute((isset($context["collector"]) ? $context["collector"] : $this->getContext($context, "collector")), "hasexception"))) {
            // line 28
            echo "        <p>
            <em>No exception was thrown and uncaught during the request.</em>
        </p>
    ";
        } else {
            // line 32
            echo "        <div class=\"sf-reset\">
            ";
            // line 33
            echo $this->env->getExtension('http_kernel')->renderFragment($this->env->getExtension('routing')->getPath("_profiler_exception", array("token" => (isset($context["token"]) ? $context["token"] : $this->getContext($context, "token")))));
            echo "
        </div>
    ";
        }
    }

    public function getTemplateName()
    {
        return "WebProfilerBundle:Collector:exception.html.twig";
    }

    public function isTraitable()
    {
        return false;
    }

    public function getDebugInfo()
    {
        return array (  462 => 202,  446 => 197,  441 => 196,  431 => 189,  394 => 168,  205 => 30,  234 => 94,  297 => 118,  956 => 271,  953 => 270,  946 => 302,  942 => 300,  933 => 296,  925 => 292,  917 => 291,  914 => 290,  912 => 289,  909 => 288,  901 => 285,  898 => 284,  890 => 281,  887 => 280,  879 => 277,  870 => 274,  868 => 273,  863 => 269,  853 => 261,  848 => 258,  840 => 253,  834 => 249,  832 => 248,  822 => 244,  820 => 243,  816 => 241,  810 => 238,  807 => 237,  805 => 236,  802 => 235,  799 => 234,  791 => 262,  788 => 233,  773 => 264,  771 => 232,  768 => 231,  765 => 230,  757 => 221,  743 => 217,  738 => 214,  732 => 213,  720 => 211,  713 => 209,  688 => 202,  682 => 201,  679 => 200,  673 => 198,  668 => 197,  665 => 196,  663 => 195,  660 => 194,  657 => 193,  647 => 191,  632 => 187,  629 => 186,  626 => 184,  610 => 181,  603 => 179,  600 => 178,  588 => 175,  570 => 164,  561 => 161,  554 => 224,  522 => 156,  479 => 135,  471 => 129,  451 => 120,  418 => 112,  373 => 156,  370 => 101,  356 => 126,  624 => 224,  620 => 223,  612 => 220,  601 => 216,  594 => 176,  585 => 209,  580 => 207,  574 => 205,  572 => 204,  566 => 203,  559 => 201,  551 => 221,  545 => 198,  526 => 190,  507 => 156,  497 => 156,  485 => 124,  463 => 117,  447 => 113,  424 => 114,  412 => 126,  410 => 110,  406 => 111,  404 => 90,  401 => 172,  391 => 163,  376 => 103,  369 => 148,  359 => 144,  333 => 132,  329 => 131,  326 => 86,  318 => 86,  261 => 104,  195 => 112,  306 => 95,  303 => 122,  292 => 119,  287 => 77,  280 => 87,  178 => 66,  12 => 36,  118 => 49,  778 => 267,  763 => 244,  760 => 222,  748 => 242,  745 => 241,  742 => 240,  736 => 238,  734 => 237,  717 => 210,  714 => 232,  711 => 231,  703 => 226,  700 => 205,  653 => 218,  650 => 192,  644 => 190,  633 => 209,  616 => 182,  599 => 215,  595 => 205,  587 => 203,  584 => 173,  581 => 201,  578 => 200,  573 => 198,  546 => 175,  534 => 162,  531 => 225,  521 => 182,  513 => 230,  499 => 173,  475 => 169,  473 => 168,  468 => 128,  454 => 121,  448 => 119,  445 => 152,  429 => 188,  422 => 184,  399 => 139,  396 => 138,  348 => 140,  345 => 116,  340 => 91,  330 => 103,  307 => 123,  300 => 121,  291 => 115,  286 => 112,  190 => 72,  321 => 128,  295 => 100,  274 => 111,  242 => 82,  236 => 92,  70 => 19,  1414 => 421,  1408 => 419,  1402 => 417,  1400 => 416,  1398 => 415,  1394 => 414,  1385 => 413,  1383 => 412,  1380 => 411,  1367 => 405,  1361 => 403,  1355 => 401,  1353 => 400,  1351 => 399,  1347 => 398,  1341 => 397,  1339 => 396,  1336 => 395,  1323 => 389,  1317 => 387,  1311 => 385,  1309 => 384,  1307 => 383,  1303 => 382,  1297 => 381,  1291 => 380,  1287 => 379,  1283 => 378,  1279 => 377,  1273 => 376,  1271 => 375,  1268 => 374,  1256 => 369,  1251 => 368,  1249 => 367,  1246 => 366,  1237 => 360,  1231 => 358,  1228 => 357,  1223 => 356,  1221 => 355,  1218 => 354,  1211 => 349,  1202 => 347,  1198 => 346,  1195 => 345,  1192 => 344,  1190 => 343,  1187 => 342,  1179 => 338,  1177 => 337,  1174 => 336,  1168 => 332,  1162 => 330,  1159 => 329,  1157 => 328,  1154 => 327,  1145 => 322,  1143 => 321,  1118 => 320,  1115 => 319,  1112 => 318,  1109 => 317,  1106 => 316,  1103 => 315,  1100 => 314,  1098 => 313,  1095 => 312,  1088 => 308,  1084 => 307,  1079 => 306,  1077 => 305,  1074 => 304,  1067 => 299,  1064 => 298,  1056 => 293,  1053 => 292,  1051 => 291,  1048 => 290,  1040 => 285,  1036 => 284,  1032 => 283,  1029 => 282,  1027 => 281,  1024 => 280,  1016 => 276,  1014 => 272,  1012 => 271,  1009 => 270,  1004 => 266,  982 => 261,  979 => 260,  976 => 259,  973 => 258,  970 => 257,  967 => 256,  964 => 255,  961 => 254,  958 => 253,  955 => 252,  952 => 251,  950 => 269,  947 => 249,  939 => 243,  936 => 297,  934 => 241,  931 => 295,  923 => 236,  920 => 235,  918 => 234,  915 => 233,  903 => 286,  900 => 228,  897 => 227,  894 => 226,  892 => 282,  889 => 224,  881 => 278,  878 => 219,  876 => 276,  873 => 217,  865 => 272,  862 => 212,  860 => 268,  857 => 267,  849 => 206,  846 => 205,  844 => 204,  841 => 203,  833 => 199,  830 => 198,  828 => 246,  825 => 196,  817 => 192,  814 => 191,  812 => 190,  809 => 189,  801 => 185,  798 => 184,  796 => 233,  793 => 182,  785 => 232,  783 => 177,  780 => 303,  772 => 248,  769 => 247,  767 => 246,  764 => 169,  756 => 165,  753 => 220,  751 => 163,  749 => 218,  746 => 161,  739 => 239,  729 => 235,  724 => 154,  721 => 153,  715 => 151,  712 => 150,  710 => 149,  707 => 208,  699 => 142,  697 => 141,  696 => 204,  695 => 139,  694 => 138,  689 => 137,  680 => 134,  675 => 132,  662 => 125,  658 => 124,  654 => 123,  649 => 122,  643 => 120,  640 => 211,  638 => 210,  619 => 183,  617 => 112,  614 => 111,  598 => 107,  596 => 106,  593 => 105,  576 => 199,  564 => 162,  557 => 96,  550 => 187,  547 => 93,  527 => 91,  515 => 305,  512 => 84,  509 => 228,  503 => 81,  496 => 172,  493 => 143,  478 => 74,  467 => 72,  456 => 68,  450 => 114,  428 => 116,  414 => 144,  408 => 176,  390 => 136,  388 => 42,  377 => 129,  371 => 35,  363 => 32,  350 => 26,  342 => 137,  335 => 134,  332 => 88,  316 => 132,  313 => 84,  290 => 90,  276 => 110,  266 => 106,  263 => 105,  255 => 353,  245 => 83,  207 => 75,  194 => 70,  76 => 25,  200 => 72,  184 => 75,  58 => 20,  170 => 96,  563 => 202,  560 => 191,  558 => 160,  553 => 188,  549 => 182,  543 => 174,  537 => 159,  532 => 192,  528 => 160,  525 => 157,  523 => 189,  518 => 180,  514 => 167,  511 => 166,  508 => 165,  501 => 154,  491 => 157,  487 => 156,  460 => 123,  455 => 115,  449 => 198,  442 => 151,  439 => 195,  436 => 132,  433 => 149,  426 => 58,  420 => 146,  415 => 180,  411 => 143,  405 => 108,  403 => 48,  380 => 160,  366 => 150,  354 => 101,  331 => 135,  325 => 129,  308 => 126,  304 => 122,  272 => 108,  267 => 101,  249 => 74,  216 => 79,  155 => 87,  146 => 81,  126 => 47,  124 => 68,  188 => 20,  181 => 65,  161 => 63,  320 => 127,  317 => 127,  311 => 128,  288 => 114,  284 => 114,  279 => 77,  275 => 105,  256 => 96,  250 => 99,  237 => 92,  232 => 91,  222 => 85,  191 => 67,  153 => 56,  150 => 55,  110 => 60,  692 => 399,  683 => 223,  678 => 133,  676 => 199,  666 => 222,  661 => 220,  656 => 219,  652 => 376,  645 => 369,  641 => 189,  635 => 188,  631 => 364,  625 => 361,  615 => 354,  607 => 180,  597 => 177,  590 => 204,  583 => 334,  579 => 332,  577 => 206,  575 => 328,  569 => 325,  565 => 324,  555 => 200,  548 => 176,  540 => 160,  536 => 194,  529 => 159,  524 => 90,  516 => 294,  510 => 178,  504 => 155,  500 => 291,  495 => 158,  490 => 142,  486 => 286,  482 => 136,  470 => 121,  464 => 125,  459 => 116,  452 => 268,  434 => 118,  421 => 90,  417 => 145,  400 => 47,  385 => 159,  361 => 146,  344 => 24,  339 => 191,  324 => 110,  310 => 83,  302 => 79,  296 => 121,  282 => 161,  259 => 103,  244 => 96,  231 => 69,  226 => 84,  215 => 37,  186 => 69,  152 => 86,  114 => 62,  104 => 35,  358 => 123,  351 => 141,  347 => 140,  343 => 92,  338 => 135,  327 => 131,  323 => 128,  319 => 124,  315 => 125,  301 => 80,  299 => 8,  293 => 90,  289 => 113,  281 => 113,  277 => 112,  271 => 110,  265 => 106,  262 => 98,  260 => 363,  257 => 103,  251 => 101,  248 => 94,  239 => 93,  228 => 88,  225 => 86,  213 => 78,  211 => 83,  197 => 71,  174 => 98,  148 => 83,  134 => 54,  127 => 62,  270 => 102,  253 => 78,  233 => 87,  212 => 34,  210 => 33,  206 => 57,  202 => 76,  198 => 80,  192 => 73,  185 => 66,  180 => 103,  175 => 65,  172 => 64,  167 => 95,  165 => 60,  160 => 91,  137 => 77,  113 => 48,  100 => 39,  90 => 27,  81 => 23,  65 => 22,  129 => 71,  97 => 27,  84 => 24,  34 => 14,  53 => 12,  77 => 35,  20 => 11,  23 => 5,  480 => 75,  474 => 122,  469 => 158,  461 => 70,  457 => 153,  453 => 199,  444 => 263,  440 => 148,  437 => 61,  435 => 146,  430 => 255,  427 => 143,  423 => 57,  413 => 241,  409 => 132,  407 => 238,  402 => 107,  398 => 88,  393 => 168,  387 => 164,  384 => 106,  381 => 105,  379 => 104,  374 => 128,  368 => 126,  365 => 141,  362 => 148,  360 => 128,  355 => 143,  341 => 131,  337 => 90,  322 => 93,  314 => 88,  312 => 124,  309 => 82,  305 => 124,  298 => 120,  294 => 90,  285 => 78,  283 => 97,  278 => 106,  268 => 373,  264 => 105,  258 => 72,  252 => 102,  247 => 98,  241 => 90,  229 => 85,  220 => 81,  214 => 63,  177 => 102,  169 => 95,  140 => 58,  132 => 66,  128 => 83,  107 => 59,  61 => 17,  273 => 85,  269 => 109,  254 => 102,  243 => 97,  240 => 72,  238 => 95,  235 => 63,  230 => 89,  227 => 92,  224 => 39,  221 => 41,  219 => 87,  217 => 38,  208 => 124,  204 => 82,  179 => 67,  159 => 89,  143 => 87,  135 => 76,  119 => 40,  102 => 40,  71 => 31,  67 => 20,  63 => 18,  59 => 14,  38 => 6,  94 => 44,  89 => 48,  85 => 16,  75 => 29,  68 => 33,  56 => 19,  87 => 34,  21 => 3,  26 => 4,  93 => 52,  88 => 32,  78 => 31,  46 => 13,  27 => 3,  44 => 11,  31 => 9,  28 => 10,  201 => 28,  196 => 52,  183 => 17,  171 => 81,  166 => 16,  163 => 92,  158 => 62,  156 => 58,  151 => 59,  142 => 30,  138 => 61,  136 => 72,  121 => 50,  117 => 57,  105 => 34,  91 => 33,  62 => 23,  49 => 14,  24 => 4,  25 => 6,  19 => 1,  79 => 43,  72 => 38,  69 => 29,  47 => 19,  40 => 11,  37 => 14,  22 => 2,  246 => 93,  157 => 95,  145 => 78,  139 => 77,  131 => 72,  123 => 42,  120 => 67,  115 => 56,  111 => 47,  108 => 53,  101 => 52,  98 => 51,  96 => 37,  83 => 33,  74 => 35,  66 => 26,  55 => 13,  52 => 12,  50 => 22,  43 => 12,  41 => 33,  35 => 6,  32 => 5,  29 => 7,  209 => 82,  203 => 73,  199 => 85,  193 => 51,  189 => 107,  187 => 77,  182 => 104,  176 => 63,  173 => 88,  168 => 61,  164 => 61,  162 => 59,  154 => 60,  149 => 91,  147 => 54,  144 => 80,  141 => 51,  133 => 67,  130 => 46,  125 => 51,  122 => 68,  116 => 39,  112 => 61,  109 => 52,  106 => 37,  103 => 55,  99 => 31,  95 => 51,  92 => 43,  86 => 38,  82 => 28,  80 => 27,  73 => 24,  64 => 23,  60 => 21,  57 => 21,  54 => 17,  51 => 16,  48 => 21,  45 => 9,  42 => 10,  39 => 6,  36 => 5,  33 => 4,  30 => 3,);
    }
}
