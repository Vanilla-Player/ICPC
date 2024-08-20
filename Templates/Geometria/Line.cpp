struct  line{
    pt p, vd;
    line(pt p, pt vd):p(p), vd(vd){}
    line(){}
    bool has(pt r){return dist(r)<=EPS;}
    bool seghas(pt r){return has(r)&&(r-p)*(r-(p+pq))<=EPS;}
    bool operator/(ln l){return abs(pq.unit()%l.pq.unit())<=EPS;} // 2D
	bool operator==(ln l){return *this/l&&has(l.p);}
    pt inter(line l){
        cout << "Cross product" << endl;
        int res = (vd&l.vd);
        cout << res << endl;
        if(abs(res) <= eps)return pt(9999,9999);
        long double t = ((l.p - p) & l.vd) / static_cast<long double>(res);
        //if(vd^l.vd )return  pt(9999,9999); // Numero grande para que entienda que no se intersectan
        return  p+vd*t;
    }
    double angle(ln l){return pq.angle(l.pq);}
    int side(pt r){return has(r)?0:sgn2(pq%(r-p));} 
    pt proj(pt r){return p+pq*((r-p)*pq/pq.norm2());}
};
