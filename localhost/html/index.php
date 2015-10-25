<?php

    // configuration
    require("../includes/config.php"); 
    
    //query about the user's portfolio
    //dump($_POST["username"]);
    $rows = query("SELECT * FROM portfolio WHERE id = ?", $_SESSION["id"]);
    $positions = [];
    foreach ($rows as $row)
    {
        $stock = lookup($row["symbol"]);
        if ($stock !== false)
        {
            $positions[] = [
            "name" => $stock["name"],
            "price" => $stock["price"],
            "shares" => $row["shares"],
            "symbol" => $row["symbol"]
            ];
        }
    }
	
    //query for cash remaining
    $cash = query("SELECT cash FROM users WHERE id= ? ",$_SESSION["id"]);    
    //dump($cash);
    // render portfolio
    render("portfolio.php", ["title" => "Portfolio", "positions" => $positions, "cash" => $cash ]);

?>
