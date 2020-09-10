<?php
$helper = new TimeHelper\Helper();

// xx秒前
$sec = time() - 50 ;
echo $helper->before($sec), "\n";

// xx分xx秒前
$sec = time() - 73;
echo $helper->before($sec), "\n";

// xx小时前
$sec = time() - 3950;
echo $helper->before($sec), "\n";

// xx天前
$sec = time() - 86600;
echo $helper->before($sec), "\n";

// xx月前
$sec = time() - 2597000;
echo $helper->before($sec), "\n";

// xx年前
$sec = time() - 948672000;
echo $helper->before($sec), "\n";
