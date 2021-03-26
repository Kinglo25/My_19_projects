FROM debian:buster

#update packages && install tools in debian
RUN apt-get update && apt-get upgrade -y && apt-get install -y \
	wget \
	vim \
	#install Nginx Web server
	nginx \ 
	#install MySQL/MariaDB
	mariadb-server \
	#install php
	php7.3 php-mysql php-fpm php-pdo php-gd php-cli php-mbstring

COPY ./srcs/nginx.conf /etc/nginx/sites-available/default
# COPY ./srcs/phpinfo.php /var/www/html
COPY ./srcs/wp-config.php ./tmp/wp-config.php
#install phpmyadmin
WORKDIR /var/www/html/
RUN wget https://files.phpmyadmin.net/phpMyAdmin/5.0.1/phpMyAdmin-5.0.1-english.tar.gz
RUN tar -xf phpMyAdmin-5.0.1-english.tar.gz && rm -rf phpMyAdmin-5.0.1-english.tar.gz
RUN mv phpMyAdmin-5.0.1-english phpmyadmin
COPY ./srcs/config.inc.php phpmyadmin

#install wordpress
RUN wget https://wordpress.org/latest.tar.gz
RUN tar -xvzf latest.tar.gz && rm -rf latest.tar.gz
COPY ./srcs/wp-config.php ..

#SSL
RUN openssl req -x509 -nodes -days 365 -subj "/C=BE/ST=BELGIQUE/L=Bruxelles/O=jodoigne/OU=19/CN=lmajerus" -newkey rsa:2048 -keyout /etc/ssl/nginx-selfsigned.key -out /etc/ssl/nginx-selfsigned.crt;

RUN chown -R www-data:www-data *
RUN chmod -R 755 /var/www/*

COPY ./srcs/init.sh ..
RUN rm index.nginx-debian.html

CMD bash ../init.sh
