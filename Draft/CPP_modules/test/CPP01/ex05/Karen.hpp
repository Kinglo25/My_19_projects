/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 19:59:44 by jandre            #+#    #+#             */
/*   Updated: 2021/08/17 20:46:53 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KAREN
# define KAREN
#include <iostream>

class Karen {
    private:
    void    debug(void);
    void    info(void);
    void    warning(void);
    void    error(void);

    public:
    Karen(void);
    ~Karen(void);

    void    complain(std::string level);
};


#endif