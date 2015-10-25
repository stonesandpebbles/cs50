    <ul class="nav nav-pills">
        <li><a href="quote.php">Quote</a></li>
        <li><a href="buy.php">Buy</a></li>
        <li><a href="sell.php">Sell</a></li>
        <li><a href="history.php">History</a></li>
        <li><a href="logout.php"><strong>Log Out</strong></a></li>
    </ul>
    <table class="table table-striped">

    <thead>
        <tr>
            <th>Symbol</th>
            <th>Name</th>
            <th>Shares</th>
            <th>Price</th>
            <th>TOTAL</th>
        </tr>
    </thead>
    <tbody>
        <?php
        foreach ($positions as $position)
        {
            print("<tr>");
            print("<td>" . $position["symbol"] . "</td>");
            print("<td>" . $position["name"] . "</td>");
            print("<td>" . $position["shares"] . "</td>");
            print("<td>" . "$" . $position["price"] . "</td>");
            print("<td>" . "$" . $position["shares"] * $position["price"] ."</td>");
            print("</tr>");
            }
        print("<tr>");
        ?>
        <td colspan = "4">CASH</td>
        <?php
        print("<td>" . "$". $cash['0']["cash"] ."</td>");    
        print("</tr>");
        ?>
    </tbody>
    </table>

