library("ggplot2")
stats <- read.csv("P2-Movie-Ratings.csv")

colnames(stats) <- c("film", "Genre", "criticRatings", "audienceRating", "budgetMillions", "year")
stats$year <- factor(stats$year)

criticRatings <- stats$criticRatings
audienceRatings <- stats$audienceRating

plot <- ggplot(data = stats, aes(criticRatings, audienceRating, color = stats$Genre))
plot <- plot  + geom_smooth(fill=NA)
plot <- plot + xlab("Critic Ratings") + ylab("Audience Rating") + labs(color = "Genre")

hist <- ggplot(data = stats, aes(stats$budgetMillions, fill = stats$Genre, color = I("black")))
hist <- hist + geom_histogram() + facet_grid(stats$Genre~., scales="free")

n <- ggplot(data = stats, aes(stats$audienceRating, stats$criticRatings, color = stats$Genre))
n <- n + geom_point() + facet_grid(stats$Genre~stats$year, scales="free")
n <- n + xlab("Audience Rating") + ylab(" Critic Rating") + labs(color = "Genre")

z <- ggplot(data = stats, aes(stats$audienceRating, stats$criticRatings, color = stats$Genre))
z <- z + geom_point() + geom_smooth(fill="NA")
z <- z + xlab("Audience Rating") + ylab(" Critic Rating") + labs(color = "Genre")
z <- z + facet_grid(stats$Genre~.)

t <- ggplot(data = stats, aes(stats$budgetMillions, fill = stats$Genre, color = I("black")))
t <- t + geom_histogram() + facet_grid(stats$Genre~., scales="free")















