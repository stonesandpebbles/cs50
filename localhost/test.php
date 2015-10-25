<?php 
    $arr = file($argv[1]);
    echo '<select name="concentration">';
    $count=1;
    foreach($arr as $value){
        echo '<option value="'.$count.'>'.$value.'</option>';
    }

    echo'</select>';

