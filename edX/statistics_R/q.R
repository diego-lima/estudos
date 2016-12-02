simulation <- function(p, n){
    r <- replicate (10000, sample(1:6,n,replace=TRUE))
    z <- vector('numeric', 10000)
    for (i in 1:10000){
        mean <- mean(r[,i] == 6)
        z[i] <- (mean - p) / sqrt(p*(1-p)/n)
    }
    qqnorm(z)
    abline(0,1)
    hist(c(1:10,1:10,20:30,1:100))
    return (mean(z >= 2) + mean(z <= -2))
}
p <- 0.5
n <- 5
r <- simulation(p,n)
p
n
r
abs(0.05 - r)

message("Press Return To Continue")
invisible(readLines("stdin", n=1))
